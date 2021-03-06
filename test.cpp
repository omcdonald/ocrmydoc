/* 
 * Test program for Templar library.
 * 
 * Author: Milosz Kosmider
 */

#include <iostream>
#include <cstdlib>

using namespace std;

#include "ocrengine.hpp"
#include "templar.hpp"

int main(int argc, char** argv)
{
    //run engine using data from database, write to database
    int dbconnect_status = Templar::Connect();
    int dbexecute_status = Templar::Process(1, 1);
    Templar::Close();
    cout << "Connect status: " << dbconnect_status << endl;
    cout << "Execute status: " << dbexecute_status << endl;
    
    //run engine directly
    Templar::OCREngine::Start("images/wensley.tif");
    char* ocr_output;
    ocr_output = Templar::OCREngine::Run(621, 304, 332, 88);
    cout << ocr_output;
    delete [] ocr_output;
    ocr_output = Templar::OCREngine::Run(160, 469, 1250, 408);
    cout << ocr_output;
    delete [] ocr_output;
    Templar::OCREngine::Stop();

    exit(EXIT_SUCCESS);
}
