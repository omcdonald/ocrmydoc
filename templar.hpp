/*
 * Header for library file of OCR module.
 *
 * Author: Milosz Kosmider
 */

#ifndef TEMPLAR_HPP_INCLUDED
#define TEMPLAR_HPP_INCLUDED

namespace OCR
{
    namespace Engine
    {
        /*
         * Starts the engine, returning nonzero values on errors.
         */
        int Start(const char* image_file);

        /*
         * Processes a region and returns the text therein.
         */
        char* Process(int x, int y, int w, int h);

        /*
         * Stops the engine so that it can be restarted (or just because).
         */
        void Stop();
    }
}

#endif
