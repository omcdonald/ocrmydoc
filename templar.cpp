/* 
 * Templar main library source.
 * 
 * Author: Milosz Kosmider
 */

#include "mysql++/mysql++.h"

#include "dbaccess.hpp"
#include "ocrengine.hpp"
#include "templar.hpp"

#include "reasonable_size.hpp"

namespace Templar
{
    mysqlpp::Connection conn(false);
    bool connected = false;

    int Connect()
    {
        int exit_status = 0;
        if (!connected)
        {
            char db[REASONABLE_SIZE], server[REASONABLE_SIZE],
                    user[REASONABLE_SIZE], pass[REASONABLE_SIZE];
    
            int info_status = DBAccess::GetConnectionInfo(db, server, user,
                    pass);

            if (info_status == 0)
            {
                if (conn.connect(db, server, user, pass))
                {
                    connected = true;
                }
                else
                {
                    exit_status = 1;
                }
            }
            else if (info_status == 1)
            {
                exit_status = 2;
            }
            else if (info_status == 2)
            {
                exit_status = 3;
            }
        }
        else
        {
            exit_status = 4;
        }
        return exit_status;
    }

    int Process(int fax_id, int template_id)
    {
        int exit_status = 0;
 
        if (connected)
        {
            mysqlpp::Query tiff_path_query = conn.query();
            tiff_path_query << "SELECT tiff_path FROM fax WHERE id = "
                    << mysqlpp::quote << fax_id;
            mysqlpp::StoreQueryResult tiff_path_result =
                    tiff_path_query.store();
 
            if (tiff_path_result && tiff_path_result.num_rows() == 1)
            {
                mysqlpp::Query regions_query = conn.query();
                regions_query << "SELECT x, y, w, h FROM region WHERE"
                        << "template_id = " << mysqlpp::quote << template_id;
                mysqlpp::StoreQueryResult regions_result =
                        regions_query.store();
    
                if (regions_result)
                {
                    int engine_start_status = OCREngine::Start
                            (tiff_path_result[0]["tiff_path"]);
 
                    if (engine_start_status == 0)
                    {
                        int num_rows = regions_result.num_rows();
                        for (int i = 0; i < num_rows; ++i)
                        {
                            char* extracted_text = OCREngine::Run
                                    (regions_result[i]["x"],
                                    regions_result[i]["y"],
                                    regions_result[i]["w"],
                                    regions_result[i]["h"]);

                            mysqlpp::Query insert_query = conn.query();
                            insert_query << "INSERT INTO element(fax_id,"
                                    << "element_name, contents) VALUES ("
                                    << mysqlpp::quote << fax_id << ", "
                                    << mysqlpp::quote
                                    << regions_result[i]["name"] << ", "
                                    << mysqlpp::quote << extracted_text << ")";
                            insert_query.execute();
 
                            delete [] extracted_text;
                        }
                        OCREngine::Stop();
                    }
                    else if (engine_start_status == 1)
                    {
                        exit_status = 3;
                    }
                    else if (engine_start_status == 2)
                    {
                        exit_status = 4;
                    }
                }
                else
                {
                    exit_status = 2;
                }
            }
            else
            {
                exit_status = 1;
            }
        }
        else
        {
            exit_status = 4;
        }

        return exit_status;
    }
 
    void Close()
    {
        if (connected)
        {
            conn.disconnect();
            connected = false;
        }
    }
}
