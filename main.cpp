/* 
 * Test program for Templar library.
 * 
 * Author: Milosz Kosmider
 */

#include <iostream>
#include <cstdlib>

using namespace std;

#include "templar.hpp"

int main(int argc, char** argv)
{
    Templar::Connect();

    Templar::Process(0, 0);

    Templar::Close();

    exit(EXIT_SUCCESS);
}
