/*
 * Milosz Kosmider
 */

#include <iostream>
#include <cstdlib>

#include "tesseract/baseapi.h"
#ifndef NULL
#define NULL 0L
#endif

using namespace std;

int main(int argc, char** argv)
{
    cout << "Testing." << endl;
    exit(EXIT_SUCCESS);
}

char* run_tesseract(const char* language, const unsigned char* imagedata, int bytes_per_pixel, int bytes_per_line, int width, int height)
{
    TessBaseAPI::InitWithLanguage(NULL, NULL, language, NULL, false, 0, NULL);
    char* text = TessBaseAPI::TesseractRect(imagedata, bytes_per_pixel, bytes_per_line, 0, 0, width, height);
    TessBaseAPI::End();
    
    return text;
}

