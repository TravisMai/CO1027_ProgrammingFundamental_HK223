#include "lib.h"
#include <iostream>
using namespace std;

void gameMap::printTopHorizontalBorder()
{
    cout << ' ';
    for (int j = 0; j < (7 * col + col - 1); j++)
    {
        cout << '_';
    }
    cout << '\n';
}

void gameMap::printBottomLine()
{
    for (int j = 0; j < col; j++)
    {
        cout << '|';
        for (int k = 0; k < 7; k++)
        {
            cout << '_';
        }
    }
    cout << '|' << '\n';
}

void gameMap::printTopHorizontalCellBorder()
{
    for (int j = 0; j < col; j++)
    {
        cout << '|';
        for (int k = 0; k < 7; k++)
        {
            cout << '_';
        }
    }
    cout << '|' << '\n';
}

string *&gameMap::operator[](int i)
{
    return mapMat[i];
}

void gameMap::printMap()
{
    bool cutStringFlag = false;
    string *cutStringArray = new string[col];
    for (int i = 0; i < row; i++)
    {
        if (cutStringFlag == true)
        {
            for (int j = 0; j < col; j++)
            {
                cout << '|';
                string cell = cutStringArray[j];
                if (cell.empty())
                {
                    cout << setw(8);
                }
                else
                {
                    int len = cell.length();
                    int spaces = (7 - len) / 2;
                    cout << cell;
                    cout << string(spaces, ' ');
                    cout << string(7 - len - spaces, ' ');
                }
            }
            cout << '|' << '\n';
            cutStringFlag = false;
            for (int j = 0; j < col; j++)
                cutStringArray[j] = "";
        }

        if (i > 0)
            printTopHorizontalCellBorder();
        else
            printTopHorizontalBorder();

        for (int j = 0; j < col; j++)
        {
            string cell = mapMat[i][j];
            cout << '|';
            if (cell.empty())
            {
                cout << string(7, ' ');
            }
            else
            {
                int len = cell.length();
                if (len <= 6)
                {
                    int spaces = (7 - len) / 2;
                    cout << cell;
                    cout << string(spaces, ' ');
                    cout << string(7 - len - spaces, ' ');
                }
                else
                {
                    cout << cell.substr(0, 5) << "_ ";
                    cutStringFlag = true;
                    cutStringArray[j] = cell.substr(5);
                }
            }
        }
        cout << '|' << '\n';
    }

    if (cutStringFlag == true)
    {
        for (int j = 0; j < col; j++)
        {
            cout << '|';
            string cell = cutStringArray[j];
            if (cell.empty())
            {
                cout << setw(8);
            }
            else
            {
                int len = cell.length();
                int spaces = (7 - len) / 2;
                cout << cell;
                cout << string(spaces, ' ');
                cout << string(7 - len - spaces, ' ');
            }
        }
        cout << '|' << '\n';
        cutStringFlag = false;
        for (int j = 0; j < col; j++)
            cutStringArray[j] = "";
    }

    printBottomLine();
}

gameMap::gameMap(string **inputMat, int r, int c) : mapMat(inputMat), row(r), col(c) {}

gameMap::~gameMap()
{
    for (int i = 0; i < row; i++)
    {
        delete[] mapMat[i];
    }
    delete[] mapMat;
}

zodiac::zodiac(const string &id, const point &loc) : ID(id), location(loc), status("Stuck") {}
rat::rat(const string &id, const point &loc) : zodiac(id, loc) {}
ox::ox(const string &id, const point &loc) : zodiac(id, loc) {}
tiger::tiger(const string &id, const point &loc) : zodiac(id, loc) {}
cat::cat(const string &id, const point &loc) : zodiac(id, loc) {}
dragon::dragon(const string &id, const point &loc) : zodiac(id, loc) {}
snake::snake(const string &id, const point &loc) : zodiac(id, loc) {}
horse::horse(const string &id, const point &loc) : zodiac(id, loc) {}
goat::goat(const string &id, const point &loc) : zodiac(id, loc) {}
monkey::monkey(const string &id, const point &loc) : zodiac(id, loc) {}
rooster::rooster(const string &id, const point &loc) : zodiac(id, loc) {}
dog::dog(const string &id, const point &loc) : zodiac(id, loc) {}
boar::boar(const string &id, const point &loc) : zodiac(id, loc) {}

void zodiac::printInfo() const {}

void zodiac::printCommonInfo() const
{
    cout << ID << " at (" << location.x << "," << location.y << ")\n";
}

void rat::printInfo() const
{
    cout << "rat ";
    printCommonInfo();
}

void ox::printInfo() const
{
    cout << "ox ";
    printCommonInfo();
}

void tiger::printInfo() const
{
    cout << "tiger ";
    printCommonInfo();
}

void cat::printInfo() const
{
    cout << "cat ";
    printCommonInfo();
}

void dragon::printInfo() const
{
    cout << "dragon ";
    printCommonInfo();
}

void snake::printInfo() const
{
    cout << "snake ";
    printCommonInfo();
}

void horse::printInfo() const
{
    cout << "horse ";
    printCommonInfo();
}

void goat::printInfo() const
{
    cout << "goat ";
    printCommonInfo();
}

void monkey::printInfo() const
{
    cout << "monkey ";
    printCommonInfo();
}

void rooster::printInfo() const
{
    cout << "rooster ";
    printCommonInfo();
}

void dog::printInfo() const
{
    cout << "dog ";
    printCommonInfo();
}

void boar::printInfo() const
{
    cout << "boar ";
    printCommonInfo();
}

void zodiac::move(const point &goalLocation, const gameMap &gameMap) {}

void rat::move(const point &goalLocation, const gameMap &gameMap) {}
void ox::move(const point &goalLocation, const gameMap &gameMap) {}
void tiger::move(const point &goalLocation, const gameMap &gameMap) {}
void cat::move(const point &goalLocation, const gameMap &gameMap) {}
void dragon::move(const point &goalLocation, const gameMap &gameMap) {}
void snake::move(const point &goalLocation, const gameMap &gameMap) {}
void horse::move(const point &goalLocation, const gameMap &gameMap) {}
void goat::move(const point &goalLocation, const gameMap &gameMap) {}
void monkey::move(const point &goalLocation, const gameMap &gameMap) {}
void rooster::move(const point &goalLocation, const gameMap &gameMap) {}
void dog::move(const point &goalLocation, const gameMap &gameMap) {}
void boar::move(const point &goalLocation, const gameMap &gameMap) {}