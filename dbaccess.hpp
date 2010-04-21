/* 
 * Database credentials header.
 * 
 * Author: Milosz Kosmider
 */

namespace Templar
{
    namespace DBAccess
    {
        /* 
         * Gets the database connection credentials.
         * 
         * Exit codes:
         *  0: Success!
         *  1: Could not find file.
         *  2: File is too short to contain all the credentials.
         */
        int GetConnectionInfo(char* db, char* server, char* user, char* pass);
    }
}
