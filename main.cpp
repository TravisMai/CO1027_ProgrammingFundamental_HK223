#include <iostream>
#include "lib.h"
using namespace std;

int main()
{

    string tempMap[50][50] =
        {{"W", "W", "WA1B1C1D1E1F", "A", "S"},
         {"W", "W", "W", "W", "S"},
         {"W", "S", "D", "D", "S"},
         {"W", "S", "D", "D", "S"},
         {"W", "SA1B1C1D1", "A", "A", "A"},
         {"W", "SA1B1C1D1", "A", "A", "A"},
         {"W", "SA1B1C1D1", "A", "A", "A"},
         {"W", "SA1B1C1D1", "A", "A", "A"}};
    int r = 8;
    int c = 5;
    string **Map = new string *[r];
    for (int i = 0; i < r; i++)
    {
        Map[i] = new string[c];
        for (int j = 0; j < c; j++)
        {
            Map[i][j] = tempMap[i][j];
        }
    }
    gameMap gMap(Map, r, c);
    // gMap.printMap();
    // rat r1("R1", point(1, 4));
    // r1.printInfo();
    // cat c2("C2", point(2, 5));
    // c2.printInfo();
    // dragon d1("D1", point(4, 4));
    // d1.printInfo();
    // dog d2("D2", point(3, 5));
    // d2.printInfo();
    dog d1("D3", point(1, 4));
    zodiac *pr1 = &d1;
    pr1->printInfo();
}