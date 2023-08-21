#include <iostream>
#include "lib.h"
using namespace std;

int main()
{

    // gMap.printMap();
    // rat r1("R1", point(1, 4));
    // r1.printInfo();
    // cat c2("C2", point(2, 5));
    // c2.printInfo();
    // dragon d1("D1", point(4, 4));
    // d1.printInfo();
    // dog d2("D2", point(3, 5));
    // d2.printInfo();
    // dog d1("D3", point(1, 4));
    // zodiac *pr1 = &d1;
    // pr1->printInfo();

    // zoList zodiacList;

    // zodiacList.add(new rat("R1", point(2, 3)));
    // zodiacList.add(new monkey("M1", point(10, 41)));

    // zodiacList[0]->printInfo();
    // zodiacList[1]->printInfo();

    // string **mapArray = new string *[9];
    // for (int i = 0; i < 9; i++)
    // {
    //     mapArray[i] = new string[9];
    // }

    // gameMap map(mapArray, 9, 9);
    string tempMap[50][50] =
        {{"", "", "", "", "", "", "", "W", "", "S"},
         {"O", "", "", "", "", "S", "", "", "", "S"},
         {"W", "", "", "", "", "W", "", "", "", "S"},
         {"", "T", "", "", "", "", "", "", "", "S"},
         {"", "", "T", "", "O", "", "", "W", "", "S"},
         {"", "", "", "", "", "", "", "W", "", "S"},
         {"", "", "", "", "", "", "", "", "", "S"},
         {"", "S", "", "S", "S", "WT", "", "W", "", "T"}};
    int r = 8;
    int c = 10;
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
    Game game(gMap);

    game.addZo(new dragon("DR1", point(0, 0)));
    game.addZo(new cat("C2", point(0, 0)));
    game.addZo(new goat("G1", point(3, 0)));
    game.addZo(new ox("O1", point(1, 2)));
    game.addZo(new tiger("T1", point(1, 2)));
    game.addZo(new snake("S1", point(1, 2)));
    // game.addZo(new tiger("T2", point(6, 8)));
    // game.addZo(new dragon("DR2", point(6, 8)));
    // game.addZo(new cat("C1", point(2, 5)));
    // game.addZo(new dog("D1", point(3, 4)));
    // game.addZo(new monkey("M1", point(7, 9)));

    game.startGame(point(6, 9), 1); // Set to true to print map during the game

    return 0;
}