/* 
 * Templar OCR engine header.
 * 
 * Author: Milosz Kosmider
 */

#ifndef OCRENGINE_HPP_INCLUDED
#define OCRENGINE_HPP_INCLUDED

namespace Templar
{
    namespace OCREngine
    {
        /* 
         * Starts the engine, returning nonzero values on errors.
         * 
         * The engine is initialized with the image at the given path. All
         * subsequent calls to Run will pull text from this image until Stop is
         * called.
         * 
         * Exit codes:
         *  0: Success!
         *  1: Failed to open image.
         *  2: Programmer error... OCREngine has already been started. Call
         *     Stop first.
         */
        int Start(const char* image_file);

        /* 
         * Performs OCR on a region and returns the text therein.
         * 
         * The region that is processed is the intersection of the image and
         * the region defined by the given coordinates. This way, out-of-bounds
         * errors are avoided.
         * 
         * The pointer returned by this function points to a dynamically
         * allocated space. This space must be freed using delete[] to avoid
         * memory leaks.
         * 
         * This function has no fail condition. If the engine has not been
         * started, a null pointer is returned.
         */
        char* Run(int x, int y, int w, int h);

        /* 
         * Stops the engine so that it can be restarted.
         * 
         * This function should be called even the last time the engine is
         * used, for consistency (but it doesn't matter from a functionality
         * perspective).
         * 
         * This function has no fail condition. If the engine has not been
         * started, nothing happens.
         */
        void Stop();
    }
}

#endif
