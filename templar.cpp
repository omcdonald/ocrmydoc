/*
 * Source for library file of OCR module.
 * 
 * Author: Milosz Kosmider
 */

#include "tesseract/baseapi.h"
#include "tesseract/imgs.h"
#include "tiffio.h"

void read_tiff_image(TIFF* tif, IMAGE* image); //Why is this necessary?

#include "sax.hpp"
#include "templar.hpp"

#ifndef NULL
#define NULL 0L
#define NULL_DEFINED
#endif

namespace OCR {
    namespace Engine {
        bool initialized = false;
        IMAGE image;
        int bytes_per_line;
        int bytes_per_pixel;
        
        int Start(const char* image_file)
        {
            int exit_status = 0;
            if (!initialized)
            {
                TIFF* tiff = NULL;
                tiff = TIFFOpen(image_file, "r");
                
                if (tiff != NULL)
                {
                    read_tiff_image(tiff, &image);
                    
                    int xsize = image.get_xsize();
                    int ysize = image.get_ysize();
                    int bpp = image.get_bpp();
                    
                    bytes_per_line = check_legal_image_size(xsize, ysize, bpp);
                    bytes_per_pixel = bpp/8;
                        
                    ::TessBaseAPI::SimpleInit(NULL, "eng", false);
                    
                    initialized = true;
                }
                else
                {
                    exit_status = 2;
                }

                TIFFClose(tiff);
            }
            else
            {
                exit_status = 1;
            }

            return exit_status;
        }
        
        char* Process(int x, int y, int w, int h)
        {
            if (initialized)
            {
                return ::TessBaseAPI::TesseractRect(image.get_buffer(),
                        bytes_per_pixel, bytes_per_line, x, y, w, h);
            }
            else
            {
                return NULL;
            }
        }
        
        void Stop()
        {
            if (initialized)
            {
                ::TessBaseAPI::End();
                initialized = false;
            }
        }        
    }
}

#ifdef NULL_DEFINED
#undef NULL
#undef NULL_DEFINED
#endif
