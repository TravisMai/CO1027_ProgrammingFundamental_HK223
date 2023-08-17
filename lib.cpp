#include "lib.h"
#include <iostream>
using namespace std;

int goalDistance(int x, int y)
{
    return abs(x - y);
}

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

gameMap::gameMap(const gameMap &other)
{
    row = other.row;
    col = other.col;
    mapMat = new string *[row];
    for (int i = 0; i < row; i++)
    {
        mapMat[i] = new string[col];
        for (int j = 0; j < col; j++)
        {
            mapMat[i][j] = other.mapMat[i][j];
        }
    }
}

gameMap::~gameMap()
{
    for (int i = 0; i < row; i++)
    {
        delete[] mapMat[i];
    }
    delete[] mapMat;
}

zodiac::zodiac(const string &id, const point &loc) : ID(id), location(loc), status("") {}
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

void zodiac::move(const point &goalLocation, const gameMap &gameMapMat, const gameMap &gameClone) {}
void rat::move(const point &goalLocation, const gameMap &gameMapMat, const gameMap &gameClone)
{
    // int x = this->location.x + 2;
    // int y = this->location.y + 2;
    // if (gameMap.mapMat[x][y].empty())
    //     gameMap.mapMat[x][y] = this->ID;
    // else
    //     gameMap.mapMat[x][y] += this->ID;
}
void ox::move(const point &goalLocation, const gameMap &gameMapMat, const gameMap &gameClone) {}
void tiger::move(const point &goalLocation, const gameMap &gameMapMat, const gameMap &gameClone) {}
void cat::move(const point &goalLocation, const gameMap &gameMapMat, const gameMap &gameClone) {}
void dragon::move(const point &goalLocation, const gameMap &gameMapMat, const gameMap &gameClone) {}
void snake::move(const point &goalLocation, const gameMap &gameMapMat, const gameMap &gameClone) {}
void horse::move(const point &goalLocation, const gameMap &gameMapMat, const gameMap &gameClone) {}
void goat::move(const point &goalLocation, const gameMap &gameMapMat, const gameMap &gameClone) {}
void monkey::move(const point &goalLocation, const gameMap &gameMapMat, const gameMap &gameClone) {}
void rooster::move(const point &goalLocation, const gameMap &gameMapMat, const gameMap &gameClone) {}
void dog::move(const point &goalLocation, const gameMap &gameMapMat, const gameMap &gameClone) {}
void boar::move(const point &goalLocation, const gameMap &gameMapMat, const gameMap &gameClone)
{
    // cout << this->location.x << " " << this->location.y << endl;
    int distanceToGoalHorizontal = goalDistance(this->location.x, goalLocation.x);
    int distanceToGoalVertical = goalDistance(this->location.y, goalLocation.y);

    if (distanceToGoalHorizontal >= distanceToGoalVertical)
    {
        if (this->location.x > goalLocation.x)
            this->location.x--;
        else
            this->location.x++;
    }
    else
    {
        if (this->location.y > goalLocation.y)
            this->location.y--;
        else
            this->location.y++;
    }
    if (gameMapMat.mapMat[this->location.y][this->location.x].empty())
    {
        gameMapMat.mapMat[this->location.y][this->location.x] = this->ID;
    }
    else
    {
        // cout << gameClone << endl;
        // cout << "game clone " << gameClone.mapMat[1][1] << endl;
        if (gameClone.mapMat[this->location.y][this->location.x] == "W" || gameClone.mapMat[this->location.y][this->location.x] == "S")
        {
            gameMapMat.mapMat[this->location.y][this->location.x] = this->ID;
            gameClone.mapMat[this->location.y][this->location.x] = "";
        }
        else
            gameMapMat.mapMat[this->location.y][this->location.x] += this->ID;
    }
}

zoList::zoList() : maxSize(12), size(0)
{
    zList = new zodiac *[maxSize];
}

zoList::~zoList()
{
    for (int i = 0; i < size; i++)
    {
        delete zList[i];
    }
    delete[] zList;
}

void zoList::add(zodiac *newZodiac)
{
    if (size < maxSize)
    {
        zList[size] = newZodiac;
        size++;
    }
}

zodiac *&zoList::operator[](int i)
{
    if (i >= 0 && i < size)
    {
        return zList[i];
    }
    return zList[0];
}

Game::Game(const gameMap &m) : mapMat(m) {}

void Game::addZo(zodiac *k)
{
    zList.add(k);
}

// gameMap mapClone(nullptr, 0, 0);

void Game::startGame(point goalLocation, bool printMapFlag = 0)
{
    mapMat[goalLocation.y][goalLocation.x] = 'G';
    gameMap mapClone = mapMat;
    for (int i = 0; i < zList.size; i++)
    {
        if (mapMat.mapMat[zList[i]->location.y][zList[i]->location.x].empty())
            mapMat.mapMat[zList[i]->location.y][zList[i]->location.x] = zList[i]->ID;
        else
            mapMat.mapMat[zList[i]->location.y][zList[i]->location.x] += zList[i]->ID;
    }

    int counter = 0;

    while (true && counter < 5)
    {
        counter++;
        if (printMapFlag)
        {
            // cout << "real map\n";
            mapMat.printMap();
            // cout << "clone map\n";
            // mapClone.printMap();
        }

        bool allStuck = true;
        bool winnerFound = false;

        for (int i = 0; i < mapMat.row; i++)
        {
            for (int j = 0; j < mapMat.col; j++)
            {
                mapMat[i][j] = mapClone[i][j];
            }
        }

        for (int i = 0; i < zList.size; i++)
        {
            zodiac *setStartLocation = zList[i];
            setStartLocation->startLocation.x = zList[i]->location.x;
            setStartLocation->startLocation.y = zList[i]->location.y;
        }

        for (int i = 0; i < zList.size; i++)
        {
            zodiac *currentZodiac = zList[i];
            if (currentZodiac->status != "Stuck")
            {
                allStuck = false;
                currentZodiac->move(goalLocation, mapMat, mapClone);
            }
            if (currentZodiac->location.x == goalLocation.x && currentZodiac->location.y == goalLocation.y)
            {
                mapMat.printMap();
                winnerFound = true;
            }
        }
        if (allStuck || winnerFound)
        {
            if (winnerFound)
            {
                cout << "Congratulations! We have a winner!\n";
                for (int i = 0; i < zList.size; i++)
                {
                    zList[i]->printInfo();
                }
            }
            else
            {
                cout << "All zodiacs are stuck. No winner this time.\n";
            }
            break;
        }
    }
}