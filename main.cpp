#include <iostream>
#include "lib.h"
using namespace std;

int main()
{
    string tempMap[50][50] =
        {{"", "", "", "S", "", "", "", "W", "", "S"},
         {"O", "", "", "", "", "S", "", "", "", "S"},
         {"W", "", "", "", "", "W", "", "", "", "S"},
         {"", "", "T", "S", "W", "", "", "", "", "S"},
         {"", "", "T", "", "O", "", "", "W", "", "S"},
         {"", "", "", "", "", "", "", "W", "", "S"},
         {"", "", "", "", "", "", "", "", "S", ""},
         {"", "", "", "", "", "", "", "", "S", "S"},
         {"", "", "", "", "", "", "", "", "S", "S"},
         {"", "W", "", "", "W", "W", "", "W", "W", "T"}};
    int r = 10;
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

    game.addZo(new dragon("D1", point(0, 0)));
    game.addZo(new goat("G1", point(3, 0)));
    game.addZo(new ox("O1", point(1, 2)));
    game.addZo(new cat("C2", point(0, 0)));
    game.addZo(new rat("R2", point(3, 1)));
    game.addZo(new rat("R3", point(8, 0)));
    game.addZo(new dog("D2", point(3, 4)));

    game.startGame(point(6, 9), 1);

    return 0;
}