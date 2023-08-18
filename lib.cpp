#include "lib.h"
#include <iostream>
using namespace std;

// ================================== START OF SUPPORT FUNCTION ==================================

int goalDistance(int x, int y)
{
    return abs(x - y);
}

string removeZodiac(string input, const string &substring)
{
    size_t pos = input.find(substring);

    while (pos != string::npos)
    {
        input.erase(pos, substring.length());
        pos = input.find(substring);
    }

    return input;
}

string removeStone(const string &input)
{
    string result;

    for (char c : input)
    {
        if (c != 'S')
        {
            result += c;
        }
    }

    return result;
}

string removeWater(const string &input)
{
    string result;

    for (char c : input)
    {
        if (c != 'W')
        {
            result += c;
        }
    }

    return result;
}

bool findObstacles(const string &input, char obstacles)
{
    size_t pos = 0;

    while (pos < input.length())
    {
        if (input[pos] == obstacles)
        {
            if (pos + 1 < input.length() && isdigit(input[pos + 1]))
            {
                pos += 2;
            }
            else
            {
                return true;
            }
        }
        else
        {
            pos++;
        }
    }

    return false;
}

// ================================== END OF SUPPORT FUNCTION ==================================

// ================================== START OF GAME MAP INITIALIZE ==================================
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

// ================================== END OF GAME MAP INITIALIZE ==================================

// ================================== START OF CONSTRUCTOR ==================================

zodiac::zodiac(const string &id, const point &loc) : ID(id), location(loc), status("") {}

rat::rat(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "rat"; }

ox::ox(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "ox"; }

tiger::tiger(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "tiger"; }

cat::cat(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "cat"; }

dragon::dragon(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "dragon"; }

snake::snake(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "snake"; }

horse::horse(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "horse"; }

goat::goat(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "goat"; }

monkey::monkey(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "monkey"; }

rooster::rooster(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "rooster"; }

dog::dog(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "dog"; }

boar::boar(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "boar"; }

// ================================== END OF CONSTRUCTOR ==================================

// ================================== START OF ZODIAC PRINTING FUNCTION ==================================

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

// ================================== END OF ZODIAC PRINTING FUNCTION ==================================

// ================================== START OF LOCATION COMPUTE FUNCTION ==================================

void zodiac::computeLocation(const point &goalLocation, const gameMap &gameMapMat) {}

void rat::computeLocation(const point &goalLocation, const gameMap &gameMapMat) {}

void ox::computeLocation(const point &goalLocation, const gameMap &gameMapMat)
{
    int maxStep = 2;
    int distanceToGoalHorizontal = goalDistance(this->location.x, goalLocation.x);
    int distanceToGoalVertical = goalDistance(this->location.y, goalLocation.y);

    if (findObstacles(gameMapMat.mapMat[this->location.y][this->location.x], 'W'))
        maxStep = 3;
    if (findObstacles(gameMapMat.mapMat[this->location.y][this->location.x], 'O'))
        maxStep = 1;

    if (distanceToGoalHorizontal >= distanceToGoalVertical)
    {
        if (this->location.x > goalLocation.x)
            if (distanceToGoalHorizontal > maxStep)
                this->location.x -= maxStep;
            else
                this->location.x -= distanceToGoalHorizontal;
        else if (distanceToGoalHorizontal > maxStep)
            this->location.x += maxStep;
        else
            this->location.x += distanceToGoalHorizontal;
    }
    else
    {
        if (this->location.y > goalLocation.y)
            if (distanceToGoalVertical > maxStep)
                this->location.y -= maxStep;
            else
                this->location.y -= distanceToGoalVertical;
        else if (distanceToGoalVertical > maxStep)
            this->location.y += maxStep;
        else
            this->location.y += distanceToGoalVertical;
    }
}

void tiger::computeLocation(const point &goalLocation, const gameMap &gameMapMat) {}

void cat::computeLocation(const point &goalLocation, const gameMap &gameMapMat) {}

void dragon::computeLocation(const point &goalLocation, const gameMap &gameMapMat)
{
    int maxStep = 1;

    if (this->location.x > goalLocation.x)
    {
        if (this->location.y > goalLocation.y)
        {
            this->location.x -= maxStep;
            this->location.y -= maxStep;
        }
        else if (this->location.y < goalLocation.y)
        {
            this->location.x -= maxStep;
            this->location.y += maxStep;
        }
        else
        {
            this->location.x -= maxStep;
        }
    }
    else if (this->location.x < goalLocation.x)
    {
        if (this->location.y > goalLocation.y)
        {
            this->location.x += maxStep;
            this->location.y -= maxStep;
        }
        else if (this->location.y < goalLocation.y)
        {
            this->location.x += maxStep;
            this->location.y += maxStep;
        }
        else
        {
            this->location.x += maxStep;
        }
    }
    else
    {
        if (this->location.y > goalLocation.y)
        {
            this->location.y -= maxStep;
        }
        else if (this->location.y < goalLocation.y)
        {
            this->location.y += maxStep;
        }
    }
}

void snake::computeLocation(const point &goalLocation, const gameMap &gameMapMat) {}

void horse::computeLocation(const point &goalLocation, const gameMap &gameMapMat) {}

void goat::computeLocation(const point &goalLocation, const gameMap &gameMapMat)
{
    int maxStep = 2;
    int distanceToGoalHorizontal = goalDistance(this->location.x, goalLocation.x);
    int distanceToGoalVertical = goalDistance(this->location.y, goalLocation.y);
    if (distanceToGoalHorizontal >= distanceToGoalVertical)
    {
        if (this->location.x > goalLocation.x)
        {
            for (int i = this->startLocation.x; i >= (this->startLocation.x - maxStep); i--)
            {
                if (findObstacles(gameMapMat.mapMat[this->startLocation.y][i], 'W') || findObstacles(gameMapMat.mapMat[this->startLocation.y][i], 'S'))
                {
                    distanceToGoalHorizontal = (i - this->startLocation.x - 1);
                }
            }
        }
        else if (this->location.x < goalLocation.x)
        {
            for (int i = this->startLocation.x; i <= (this->startLocation.x + maxStep); i++)
            {
                if (findObstacles(gameMapMat.mapMat[this->startLocation.y][i], 'W') || findObstacles(gameMapMat.mapMat[this->startLocation.y][i], 'S'))
                {
                    distanceToGoalHorizontal = (i - this->startLocation.x - 1);
                }
            }
        }
    }
    else
    {
        if (this->location.y > goalLocation.y)
        {
            for (int i = this->startLocation.y; i >= (this->startLocation.y - maxStep); i--)
            {
                if (findObstacles(gameMapMat.mapMat[i][this->startLocation.x], 'W') || findObstacles(gameMapMat.mapMat[i][this->startLocation.y], 'S'))
                {
                    distanceToGoalHorizontal = (i - this->startLocation.y - 1);
                }
            }
        }
        else if (this->location.y < goalLocation.y)
        {
            for (int i = this->startLocation.y; i <= (this->startLocation.y + maxStep); i++)
            {
                if (findObstacles(gameMapMat.mapMat[i][this->startLocation.x], 'W') || findObstacles(gameMapMat.mapMat[i][this->startLocation.x], 'S'))
                {
                    distanceToGoalHorizontal = (i - this->startLocation.y - 1);
                }
            }
        }
    }

    if (findObstacles(gameMapMat.mapMat[this->location.y][this->location.x], 'O'))
        maxStep = 1;

    if (distanceToGoalHorizontal >= distanceToGoalVertical)
    {
        if (this->location.x > goalLocation.x)
        {
            if (distanceToGoalHorizontal > maxStep)
            {
                for (int i = this->location.x; i < (this->location.x + maxStep); i++)
                {
                    if (findObstacles(gameMapMat.mapMat[this->location.y][i], 'W') || findObstacles(gameMapMat.mapMat[this->location.y][i], 'S'))
                        this->location.x -= (i - this->location.x);
                    else
                        this->location.x -= maxStep;
                }
            }
            else
            {
                for (int i = this->location.x; i < (this->location.x + distanceToGoalHorizontal); i++)
                {
                    if (findObstacles(gameMapMat.mapMat[this->location.y][i], 'W') || findObstacles(gameMapMat.mapMat[this->location.y][i], 'S'))
                        this->location.x -= (i - this->location.x);
                    else
                        this->location.x -= distanceToGoalHorizontal;
                }
            }
        }
        else if (distanceToGoalHorizontal > maxStep)
        {
            bool isOstacle = false;
            for (int i = this->startLocation.x; i <= (this->startLocation.x + maxStep); i++)
            {
                cout << "i: " << i << endl;
                cout << findObstacles(gameMapMat.mapMat[3][i], 'S') << endl;
                cout << this->startLocation.x << " " << i << endl;
                if (findObstacles(gameMapMat.mapMat[this->startLocation.y][i], 'W') || findObstacles(gameMapMat.mapMat[this->startLocation.y][i], 'S'))
                {
                    isOstacle = true;
                    this->location.x += (i - this->startLocation.x - 1);
                    break;
                }
            }
            if (!isOstacle)
            {
                this->location.x += maxStep;
            }
        }
        else
        {
            for (int i = this->location.x; i < (this->location.x + distanceToGoalHorizontal); i++)
            {
                if (findObstacles(gameMapMat.mapMat[this->location.y][i], 'W') || findObstacles(gameMapMat.mapMat[this->location.y][i], 'S'))
                    this->location.x += (i - this->location.x);
                else
                    this->location.x += distanceToGoalHorizontal;
            }
        }
    }
    else
    {
        if (this->location.y > goalLocation.y)
            if (distanceToGoalVertical > maxStep)
            {
                for (int i = this->location.y; i < (this->location.y + maxStep); i++)
                {
                    if (findObstacles(gameMapMat.mapMat[i][this->location.x], 'W') || findObstacles(gameMapMat.mapMat[i][this->location.x], 'S'))
                        this->location.y -= (i - this->location.y);
                    else
                        this->location.y -= maxStep;
                }
            }
            else
            {
                for (int i = this->location.y; i < (this->location.y + distanceToGoalVertical); i++)
                {
                    if (findObstacles(gameMapMat.mapMat[i][this->location.x], 'W') || findObstacles(gameMapMat.mapMat[i][this->location.x], 'S'))
                        this->location.y -= (i - this->location.y);
                    else
                        this->location.y -= distanceToGoalVertical;
                }
            }
        else if (distanceToGoalVertical > maxStep)
        {
            for (int i = this->location.y; i < (this->location.y + maxStep); i++)
            {
                if (findObstacles(gameMapMat.mapMat[i][this->location.x], 'W') || findObstacles(gameMapMat.mapMat[i][this->location.x], 'S'))
                    this->location.y += (i - this->location.y);
                else
                    this->location.y += maxStep;
            }
        }
        else
        {
            for (int i = this->location.y; i < (this->location.y + distanceToGoalVertical); i++)
            {
                if (findObstacles(gameMapMat.mapMat[i][this->location.x], 'W') || findObstacles(gameMapMat.mapMat[i][this->location.x], 'S'))
                    this->location.y += (i - this->location.y);
                else
                    this->location.y += distanceToGoalVertical;
            }
        }
    }
}

void monkey::computeLocation(const point &goalLocation, const gameMap &gameMapMat) {}

void rooster::computeLocation(const point &goalLocation, const gameMap &gameMapMat) {}

void dog::computeLocation(const point &goalLocation, const gameMap &gameMapMat) {}

void boar::computeLocation(const point &goalLocation, const gameMap &gameMapMat)
{
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
}

// ================================== END OF LOCATION COMPUTE FUNCTION ==================================

// ================================== START OF MOVE FUNCTION ==================================

void zodiac::move(const point &goalLocation, const gameMap &gameMapMat) {}

void rat::move(const point &goalLocation, const gameMap &gameMapMat) {}

void ox::move(const point &goalLocation, const gameMap &gameMapMat)
{
    int distanceToGoalHorizontal = goalDistance(this->startLocation.x, goalLocation.x);
    int distanceToGoalVertical = goalDistance(this->startLocation.y, goalLocation.y);
    gameMapMat.mapMat[this->startLocation.y][this->startLocation.x] = removeZodiac(gameMapMat.mapMat[this->startLocation.y][this->startLocation.x], string(this->ID));
    if (distanceToGoalHorizontal < distanceToGoalVertical)
    {
        if (this->location.y > this->startLocation.y)
        {
            for (int i = this->startLocation.y; i < this->location.y; i++)
                gameMapMat.mapMat[i][this->location.x] = removeStone(gameMapMat.mapMat[i][this->location.x]);
        }
        else
        {
            for (int i = this->startLocation.y; i < this->location.y; i--)
                gameMapMat.mapMat[i][this->location.x] = removeStone(gameMapMat.mapMat[i][this->location.x]);
        }
    }
    else
    {
        if (this->location.x > this->startLocation.x)
        {
            for (int i = this->startLocation.x; i < this->location.x; i++)
                gameMapMat.mapMat[this->location.y][i] = removeStone(gameMapMat.mapMat[this->location.y][i]);
        }
        else
        {
            for (int i = this->startLocation.x; i > this->location.x; i--)
                gameMapMat.mapMat[this->location.y][i] = removeStone(gameMapMat.mapMat[this->location.y][i]);
        }
    }

    if (gameMapMat.mapMat[this->location.y][this->location.x].empty())
    {
        gameMapMat.mapMat[this->location.y][this->location.x] = this->ID;
    }
    else
    {
        gameMapMat.mapMat[this->location.y][this->location.x] = removeStone(gameMapMat.mapMat[this->location.y][this->location.x]);
        gameMapMat.mapMat[this->location.y][this->location.x] += this->ID;
    }
}

void tiger::move(const point &goalLocation, const gameMap &gameMapMat) {}

void cat::move(const point &goalLocation, const gameMap &gameMapMat) {}

void dragon::move(const point &goalLocation, const gameMap &gameMapMat)
{
    gameMapMat.mapMat[this->startLocation.y][this->startLocation.x] = removeZodiac(gameMapMat.mapMat[this->startLocation.y][this->startLocation.x], string(this->ID));
    if (gameMapMat.mapMat[this->location.y][this->location.x].empty())
    {
        gameMapMat.mapMat[this->location.y][this->location.x] = this->ID;
    }
    else
    {
        gameMapMat.mapMat[this->location.y][this->location.x] += this->ID;
    }
}

void snake::move(const point &goalLocation, const gameMap &gameMapMat) {}

void horse::move(const point &goalLocation, const gameMap &gameMapMat) {}

void goat::move(const point &goalLocation, const gameMap &gameMapMat)
{
    gameMapMat.mapMat[this->startLocation.y][this->startLocation.x] = removeZodiac(gameMapMat.mapMat[this->startLocation.y][this->startLocation.x], string(this->ID));
    if (gameMapMat.mapMat[this->location.y][this->location.x].empty())
    {
        gameMapMat.mapMat[this->location.y][this->location.x] = this->ID;
    }
    else
    {
        gameMapMat.mapMat[this->location.y][this->location.x] += this->ID;
    }
}

void monkey::move(const point &goalLocation, const gameMap &gameMapMat) {}

void rooster::move(const point &goalLocation, const gameMap &gameMapMat) {}

void dog::move(const point &goalLocation, const gameMap &gameMapMat) {}

void boar::move(const point &goalLocation, const gameMap &gameMapMat)
{
    gameMapMat.mapMat[this->startLocation.y][this->startLocation.x] = removeZodiac(gameMapMat.mapMat[this->startLocation.y][this->startLocation.x], string(this->ID));
    if (gameMapMat.mapMat[this->location.y][this->location.x].empty())
    {
        gameMapMat.mapMat[this->location.y][this->location.x] = this->ID;
    }
    else
    {
        gameMapMat.mapMat[this->location.y][this->location.x] = removeWater(gameMapMat.mapMat[this->location.y][this->location.x]);
        gameMapMat.mapMat[this->location.y][this->location.x] = removeStone(gameMapMat.mapMat[this->location.y][this->location.x]);
        gameMapMat.mapMat[this->location.y][this->location.x] += this->ID;
    }
}

// ================================== END OF MOVE FUNCTION ==================================

// ================================== START OF ZOLIST INITIALIZE ==================================

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

// ================================== END OF ZOLIST INITIALIZE ==================================

// ================================== START OF GAME INITIALIZE ==================================

Game::Game(const gameMap &m) : mapMat(m) {}

void Game::addZo(zodiac *k)
{
    zList.add(k);
    int x = k->location.x;
    int y = k->location.y;
    if (mapMat.mapMat[y][x].empty())
        mapMat.mapMat[y][x] = k->ID;
    else
        mapMat.mapMat[y][x] += k->ID;
}

void Game::startGame(point goalLocation, bool printMapFlag = 0)
{
    mapMat[goalLocation.y][goalLocation.x] = 'G';

    while (true)
    {
        if (printMapFlag)
        {
            mapMat.printMap();
        }

        bool allStuck = true;
        bool winnerFound = false;

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
                currentZodiac->computeLocation(goalLocation, mapMat);
            }
        }
        for (int i = 0; i < zList.size; i++)
        {
            zodiac *currentZodiac = zList[i];
            if (currentZodiac->status != "Stuck")
            {
                allStuck = false;
                currentZodiac->move(goalLocation, mapMat);
            }
            if (currentZodiac->location.x == goalLocation.x && currentZodiac->location.y == goalLocation.y)
            {
                winnerFound = true;
            }
            if (currentZodiac->location.x == currentZodiac->startLocation.x && currentZodiac->location.y == currentZodiac->startLocation.y)
            {
                currentZodiac->status = "Stuck";
            }
        }
        if (allStuck || winnerFound)
        {
            if (winnerFound)
            {
                mapMat.printMap();
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

// ================================== END OF GAME INITIALIZE ==================================