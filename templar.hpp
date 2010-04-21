/* 
 * Templar main library header.
 * 
 * Author: Milosz Kosmider
 */

#ifndef TEMPLAR_HPP_INCLUDED
#define TEMPLAR_HPP_INCLUDED

namespace Templar
{
    /* 
     * Connects to the database using the credentials supplied by dbaccess.cpp,
     * returning nonzero values on errors.
     * 
     * All subsequent calls to Process will
     * use this database connection until Close is called.
     * 
     * Exit codes:
     *  0: Success!
     *  1: Could not establish connection to database.
     *  2: database.dat does not exist.
     *  3: database.dat does not contain all the credentials.
     *  4: Programmer error... connection already exists. Call Close first.
     */
    int Connect();

    /* 
     * Pulls a fax and a template from the database based on their respective
     * IDs. Processes the fax using the template and stores the result in the
     * database.
     * 
     * Error codes:
     *  0: Success!
     *  1: Given fax ID does not exist in database.
     *  2: Given template ID does not exist in database.
     *     OR
     *     Given template exists but has no regions.
     *  3: The image pointed to by the database does not exist.
     *  4: Programmer error... OCREngine improperly initialized.
     */
    int Process(int fax_id, int template_id);

    /* 
     * Closes the current database connection so that a new one can be made.
     * 
     * This function should be called even the last time the engine is
     * used, for consistency (but it doesn't matter from a functionality
     * perspective).
     * 
     * This function has no fail condition. If no connection exists, nothing
     * happens.
     */
    void Close();
}

#endif
