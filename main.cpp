/*
 * Main program file for OCR module.
 *
 * Syntax: templar [options] <image>
 *
 * Author: Milosz Kosmider
 */

#include <iostream>
#include <cstdlib>

using namespace std;

#include "templar.hpp"

using namespace OCR;

int main(int argc, char** argv)
{
    Engine::Start("images/wensley.tif");

    cout << Engine::Process(168, 874, 1238, 140);
    cout << Engine::Process(320, 1150, 1070, 128);

    Engine::Stop();

    Engine::Start("images/albania.tif");

    cout << Engine::Process(29, 456, 703, 118);
    cout << Engine::Process(-1, 5000, 40, 30000);

    Engine::Stop();

    exit(EXIT_SUCCESS);
}
