/* 
 * Database credentials source.
 * 
 * Author: Milosz Kosmider
 */

#include <fstream>
#include <string>
using namespace std;

#include "dbaccess.hpp"

#include "reasonable_size.hpp"

namespace Templar
{
    namespace DBAccess
    {
        int GetConnectionInfo(char* db, char* server, char* user, char* pass)
        {
            int exit_status = 0;

            ifstream dat("database.dat");
            if (dat.is_open())
            {
                char* params[] = {db, server, user, pass};
                for (int i = 0; i < 4 && exit_status == 0; ++i)
                {
                    if (!dat.getline(params[i], REASONABLE_SIZE))
                    {
                        exit_status = 2;
                    }
                }
            }
            else
            {
                exit_status = 1;
            }

            return exit_status;
        }
    }
}
