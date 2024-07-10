/******************************************************************************
 * keys.cpp                                                                   *
 * demonstration of getting key input                                         *
 *                                                                            *
 * Adapted from:                                                              *
 * https://web.archive.org/web/20170407153459/http://www.doctort.org/adam/    *
 * nerd-notes/reading-single-keystroke-on-linux.html                          *
 *                                                                            *
 * Authors:                                                                   *
 * Joshua Linehan                                                             *
 ******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a character: ";
    char c, d, e;
    cin >> c;
    cin >> d;
    cin >> e;
    cout << "\nYour character was ";
    // Using 3 char type, Cause up down right left consist with 3 character
    if ((c == 27) && (d == 91))
    {
        if (e == 65)
        {
            cout << "UP";
        }
        if (e == 66)
        {
            cout << "DOWN";
        }
        if (e == 67)
        {
            cout << "RIGHT";
        }
        if (e == 68)
        {
            cout << "LEFT";
        }
    }
    cout << c << endl << d << endl << e << endl;
    return 0;
}
