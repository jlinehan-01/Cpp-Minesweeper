/******************************************************************************
 * fflush.cpp                                                                 *
 * demonstration of modifying program output                                  *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#include <iostream>

int main(int argc, char *argv[])
{
    int _;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "\r" << i << std::flush;
        std::cin.ignore();
        std::cout << "\x1b[A";
    }

    return 0;
}
