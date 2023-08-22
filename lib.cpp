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
bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}
string removeStone(const string &input)
{
    string result;
    for (int i = 0; i < input.length(); ++i)
    {
        if (input[i] == 'S')
        {
            if (i < input.length() - 1 && isDigit(input[i + 1]))
            {
                result += "S";
                while (i < input.length() && isDigit(input[i + 1]))
                {
                    result += input[i + 1];
                    ++i;
                }
            }
        }
        else
        {
            result += input[i];
        }
    }

    return result;
}
string removeWater(const string &input)
{
    string result;
    for (int i = 0; i < input.length(); ++i)
    {
        if (input[i] == 'W')
        {
            if (i < input.length() - 1 && isDigit(input[i + 1]))
            {
                result += "W";
                while (i < input.length() && isDigit(input[i + 1]))
                {
                    result += input[i + 1];
                    ++i;
                }
            }
        }
        else
        {
            result += input[i];
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
            if (pos + 1 < input.length() && isDigit(input[pos + 1]))
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
void distanceToObstacles(const point location, const point startLocation, const point goalLocation, int maxStep, string zodiacType, int &distanceToGoalHorizontal, int &distanceToGoalVertical, const gameMap &gameMapMat)
{
    if (location.x > goalLocation.x)
    {
        int tempMaxStep = maxStep;
        if (distanceToGoalVertical < maxStep)
        {
            tempMaxStep = distanceToGoalVertical;
        }
        for (int i = startLocation.x - 1; i >= (startLocation.x - tempMaxStep); i--)
        {
            if (i < 0)
                break;

            if (zodiacType != "dragon" && zodiacType != "horse")
            {
                if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'W') || findObstacles(gameMapMat.mapMat[i][startLocation.y], 'S'))
                {
                    distanceToGoalVertical = (abs(i - startLocation.x) - 1);
                    break;
                }
            }
            else if (zodiacType == "dragon")
            {
                if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'O'))
                {
                    distanceToGoalVertical = (abs(i - startLocation.x) - 1);
                    break;
                }
            }
            else
            {
                if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'W') && (i != startLocation.x - 1))
                {
                    distanceToGoalVertical = (abs(i - startLocation.x) - 1);
                    break;
                }
            }
        }
    }
    else if (location.x < goalLocation.x)
    {
        int tempMaxStep = maxStep;
        if (distanceToGoalVertical < maxStep)
        {
            tempMaxStep = distanceToGoalVertical;
        }
        for (int i = startLocation.x + 1; i <= (startLocation.x + tempMaxStep); i++)
        {
            if (i >= gameMapMat.row)
                break;

            if (zodiacType != "dragon" && zodiacType != "horse")
            {
                if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'W') || findObstacles(gameMapMat.mapMat[i][startLocation.y], 'S'))
                {
                    distanceToGoalVertical = (abs(i - startLocation.x) - 1);
                    break;
                }
            }
            else if (zodiacType == "dragon")
            {
                if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'O'))
                {
                    distanceToGoalVertical = (abs(i - startLocation.x) - 1);
                    break;
                }
            }
            else
            {
                if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'W') && (i != startLocation.x + 1))
                {
                    distanceToGoalVertical = (abs(i - startLocation.x) - 1);
                    break;
                }
            }
        }
    }
    if (location.y > goalLocation.y)
    {
        int tempMaxStep = maxStep;
        if (distanceToGoalHorizontal < maxStep)
        {
            tempMaxStep = distanceToGoalHorizontal;
        }
        for (int i = startLocation.y - 1; i >= (startLocation.y - tempMaxStep); i--)
        {
            if (i < 0)
                break;

            if (zodiacType != "dragon" && zodiacType != "horse")
            {
                if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'W') || findObstacles(gameMapMat.mapMat[startLocation.x][i], 'S'))
                {
                    distanceToGoalHorizontal = (abs(i - startLocation.y) - 1);
                    break;
                }
            }
            else if (zodiacType == "dragon")
            {
                if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'O'))
                {
                    distanceToGoalHorizontal = (abs(i - startLocation.y) - 1);
                    break;
                }
            }
            else
            {
                if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'W') && (i != startLocation.y - 1))
                {
                    distanceToGoalHorizontal = (abs(i - startLocation.y) - 1);
                    break;
                }
            }
        }
    }
    else if (location.y < goalLocation.y)
    {
        int tempMaxStep = maxStep;
        if (distanceToGoalHorizontal < maxStep)
        {
            tempMaxStep = distanceToGoalHorizontal;
        }
        for (int i = startLocation.y + 1; i <= (startLocation.y + tempMaxStep); i++)
        {
            if (i >= gameMapMat.col)
                break;
            if (zodiacType != "dragon" && zodiacType != "horse")
            {
                if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'W') || findObstacles(gameMapMat.mapMat[startLocation.x][i], 'S'))
                {
                    distanceToGoalHorizontal = (abs(i - startLocation.y) - 1);
                    break;
                }
            }
            else if (zodiacType == "dragon")
            {
                if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'O'))
                {
                    distanceToGoalHorizontal = (abs(i - startLocation.y) - 1);
                    break;
                }
            }
            else
            {
                if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'W') && (i != startLocation.y + 1))
                {
                    distanceToGoalHorizontal = (abs(i - startLocation.y) - 1);
                    break;
                }
            }
        }
    }
}
void verticalCalculation(point &location, const point startLocation, const point goalLocation, int maxStep, string zodiacType, int distanceToGoalHorizontal, int distanceToGoalVertical, const gameMap &gameMapMat);
void horizontalCalculation(point &location, const point startLocation, const point goalLocation, int maxStep, string zodiacType, int distanceToGoalHorizontal, int distanceToGoalVertical, const gameMap &gameMapMat)
{
    if (distanceToGoalHorizontal > 0)
    {
        if (location.y > goalLocation.y)
        {
            if (distanceToGoalHorizontal > maxStep)
            {
                bool isOstacle = false;
                for (int i = startLocation.y - 1; i <= (startLocation.y - maxStep); i--)
                {
                    if (i < 0)
                        break;

                    if (zodiacType != "dragon" && zodiacType != "horse")
                    {
                        if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'W') || findObstacles(gameMapMat.mapMat[startLocation.x][i], 'S'))
                        {
                            isOstacle = true;
                            location.y -= (abs(i - startLocation.y) - 1);
                            break;
                        }
                    }
                    else if (zodiacType == "dragon")
                    {
                        if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'O'))
                        {
                            isOstacle = true;
                            location.y -= (abs(i - startLocation.y) - 1);
                            break;
                        }
                    }
                    else
                    {
                        if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'W') && (i != startLocation.y - 1))
                        {
                            isOstacle = true;
                            location.y -= (abs(i - startLocation.y) - 1);
                            break;
                        }
                    }
                }
                if (!isOstacle)
                {
                    location.y -= maxStep;
                }
            }
            else
            {
                bool isOstacle = false;
                for (int i = startLocation.y - 1; i <= (startLocation.y - distanceToGoalHorizontal); i--)
                {
                    if (i < 0)
                        break;

                    if (zodiacType != "dragon" && zodiacType != "horse")
                    {
                        if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'W') || findObstacles(gameMapMat.mapMat[startLocation.x][i], 'S'))
                        {
                            isOstacle = true;
                            location.y -= (abs(i - startLocation.y) - 1);
                            break;
                        }
                    }
                    else if (zodiacType == "dragon")
                    {
                        if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'O'))
                        {
                            isOstacle = true;
                            location.y -= (abs(i - startLocation.y) - 1);
                            break;
                        }
                    }
                    else
                    {
                        if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'W') && (i != startLocation.y - 1))
                        {
                            isOstacle = true;
                            location.y -= (abs(i - startLocation.y) - 1);
                            break;
                        }
                    }
                }
                if (!isOstacle)
                {
                    location.y -= distanceToGoalHorizontal;
                }
            }
        }
        else if (distanceToGoalHorizontal > maxStep)
        {
            bool isOstacle = false;
            for (int i = startLocation.y + 1; i <= (startLocation.y + maxStep); i++)
            {
                if (i >= gameMapMat.col)
                    break;

                if (zodiacType != "dragon" && zodiacType != "horse")
                {
                    if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'W') || findObstacles(gameMapMat.mapMat[startLocation.x][i], 'S'))
                    {
                        isOstacle = true;
                        location.y += (abs(i - startLocation.y) - 1);
                        break;
                    }
                }
                else if (zodiacType == "dragon")
                {
                    if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'O'))
                    {
                        isOstacle = true;
                        location.y += (abs(i - startLocation.y) - 1);
                        break;
                    }
                }
                else
                {
                    if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'W') && (i != startLocation.y + 1))
                    {
                        isOstacle = true;
                        location.y += (abs(i - startLocation.y) - 1);
                        break;
                    }
                }
            }
            if (!isOstacle)
            {
                location.y += maxStep;
            }
        }
        else
        {
            bool isOstacle = false;
            for (int i = startLocation.y + 1; i <= (startLocation.y + distanceToGoalHorizontal); i++)
            {
                if (i >= gameMapMat.col)
                    break;

                if (zodiacType != "dragon" && zodiacType != "horse")
                {
                    if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'W') || findObstacles(gameMapMat.mapMat[startLocation.x][i], 'S'))
                    {
                        isOstacle = true;
                        location.y += (abs(i - startLocation.y) - 1);
                        break;
                    }
                }
                else if (zodiacType == "dragon")
                {
                    if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'O'))
                    {
                        isOstacle = true;
                        location.y += (abs(i - startLocation.y) - 1);
                        break;
                    }
                }
                else
                {
                    if (findObstacles(gameMapMat.mapMat[startLocation.x][i], 'W') && (i != startLocation.y + 1))
                    {
                        isOstacle = true;
                        location.y += (abs(i - startLocation.y) - 1);
                        break;
                    }
                }
            }
            if (!isOstacle)
            {
                location.y += distanceToGoalHorizontal;
            }
        }
    }
    else
    {
        verticalCalculation(location, startLocation, goalLocation, maxStep, zodiacType, distanceToGoalHorizontal, distanceToGoalVertical, gameMapMat);
    }
}
void verticalCalculation(point &location, const point startLocation, const point goalLocation, int maxStep, string zodiacType, int distanceToGoalHorizontal, int distanceToGoalVertical, const gameMap &gameMapMat)
{
    if (distanceToGoalVertical > 0)
    {
        if (location.x > goalLocation.x)
        {
            if (distanceToGoalVertical > maxStep)
            {
                bool isOstacle = false;
                for (int i = startLocation.x - 1; i <= (startLocation.x - maxStep); i--)
                {
                    if (i < 0)
                        break;

                    if (zodiacType != "dragon" && zodiacType != "horse")
                    {
                        if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'W') || findObstacles(gameMapMat.mapMat[i][startLocation.y], 'S'))
                        {
                            isOstacle = true;
                            location.x -= (abs(i - startLocation.x) - 1);
                            break;
                        }
                    }
                    else if (zodiacType == "dragon")
                    {
                        if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'O'))
                        {
                            isOstacle = true;
                            location.x -= (abs(i - startLocation.x) - 1);
                            break;
                        }
                    }
                    else
                    {
                        if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'W') && (i != startLocation.x - 1))
                        {
                            isOstacle = true;
                            location.x -= (abs(i - startLocation.x) - 1);
                            break;
                        }
                    }
                }
                if (!isOstacle)
                {
                    location.x -= maxStep;
                }
            }
            else
            {
                bool isOstacle = false;
                for (int i = startLocation.x - 1; i <= (startLocation.x - distanceToGoalVertical); i--)
                {
                    if (i < 0)
                        break;

                    if (zodiacType != "dragon" && zodiacType != "horse")
                    {
                        if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'W') || findObstacles(gameMapMat.mapMat[i][startLocation.y], 'S'))
                        {
                            isOstacle = true;
                            location.x -= (abs(i - startLocation.x) - 1);
                            break;
                        }
                    }
                    else if (zodiacType == "dragon")
                    {
                        if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'O'))
                        {
                            isOstacle = true;
                            location.x -= (abs(i - startLocation.x) - 1);
                            break;
                        }
                    }
                    else
                    {
                        if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'W') && (i != startLocation.x - 1))
                        {
                            isOstacle = true;
                            location.x -= (abs(i - startLocation.x) - 1);
                            break;
                        }
                    }
                }
                if (!isOstacle)
                {
                    location.x -= distanceToGoalVertical;
                }
            }
        }
        else if (distanceToGoalVertical > maxStep)
        {
            bool isOstacle = false;
            for (int i = startLocation.x + 1; i <= (startLocation.x + maxStep); i++)
            {
                if (i >= gameMapMat.row)
                    break;

                if (zodiacType != "dragon" && zodiacType != "horse")
                {
                    if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'W') || findObstacles(gameMapMat.mapMat[i][startLocation.y], 'S'))
                    {
                        isOstacle = true;
                        location.x += (abs(i - startLocation.x) - 1);
                        break;
                    }
                }
                else if (zodiacType == "dragon")
                {
                    if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'O'))
                    {
                        isOstacle = true;
                        location.x += (abs(i - startLocation.x) - 1);
                        break;
                    }
                }
                else
                {
                    if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'W') && (i != startLocation.x + 1))
                    {
                        isOstacle = true;
                        location.x += (abs(i - startLocation.x) - 1);
                        break;
                    }
                }
            }
            if (!isOstacle)
            {
                location.x += maxStep;
            }
        }
        else
        {
            bool isOstacle = false;
            for (int i = startLocation.x + 1; i <= (startLocation.x + distanceToGoalVertical); i++)
            {
                if (i >= gameMapMat.row)
                    break;

                if (zodiacType != "dragon" && zodiacType != "horse")
                {
                    if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'W') || findObstacles(gameMapMat.mapMat[i][startLocation.y], 'S'))
                    {
                        isOstacle = true;
                        location.x += (abs(i - startLocation.x) - 1);
                        break;
                    }
                }
                else if (zodiacType == "dragon")
                {
                    if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'O'))
                    {
                        isOstacle = true;
                        location.x += (abs(i - startLocation.x) - 1);
                        break;
                    }
                }
                else
                {
                    if (findObstacles(gameMapMat.mapMat[i][startLocation.y], 'W') && (i != startLocation.x + 1))
                    {
                        isOstacle = true;
                        location.x += (abs(i - startLocation.x) - 1);
                        break;
                    }
                }
            }
            if (!isOstacle)
            {
                location.x += distanceToGoalVertical;
            }
        }
    }
    else
    {
        horizontalCalculation(location, startLocation, goalLocation, maxStep, zodiacType, distanceToGoalHorizontal, distanceToGoalVertical, gameMapMat);
    }
}
void defaultComputeLocation(point &location, point &startLocation, const point goalLocation, int maxStep, string &status, string zodiacType, const gameMap &gameMapMat)
{
    int distanceToGoalHorizontal = goalDistance(location.y, goalLocation.y);
    int distanceToGoalVertical = goalDistance(location.x, goalLocation.x);

    int ogirinalHorizontal = distanceToGoalHorizontal;
    int ogirinalVertical = distanceToGoalVertical;

    distanceToObstacles(location, startLocation, goalLocation, maxStep, zodiacType, distanceToGoalHorizontal, distanceToGoalVertical, gameMapMat);

    if ((distanceToGoalHorizontal == 0) && (distanceToGoalVertical == 0))
    {
        status = "Stuck";
    }
    else
    {
        status = "";
        if (findObstacles(gameMapMat.mapMat[location.x][location.y], 'O'))
            maxStep = 1;

        if (ogirinalHorizontal < ogirinalVertical)
            verticalCalculation(location, startLocation, goalLocation, maxStep, zodiacType, distanceToGoalHorizontal, distanceToGoalVertical, gameMapMat);
        else
            horizontalCalculation(location, startLocation, goalLocation, maxStep, zodiacType, distanceToGoalHorizontal, distanceToGoalVertical, gameMapMat);
    }
}
void computeOxBoarMonkey(point &location, const point goalLocation, int maxStep, const gameMap &gameMapMat)
{
    int distanceToGoalHorizontal = goalDistance(location.y, goalLocation.y);
    int distanceToGoalVertical = goalDistance(location.x, goalLocation.x);

    if (distanceToGoalHorizontal < distanceToGoalVertical)
    {
        if (location.x > goalLocation.x)
            if (distanceToGoalVertical > maxStep)
                location.x -= maxStep;
            else
                location.x -= distanceToGoalVertical;
        else if (distanceToGoalVertical > maxStep)
            location.x += maxStep;
        else
            location.x += distanceToGoalVertical;
    }
    else
    {
        if (location.y > goalLocation.y)
            if (distanceToGoalHorizontal > maxStep)
                location.y -= maxStep;
            else
                location.y -= distanceToGoalHorizontal;
        else if (distanceToGoalHorizontal > maxStep)
            location.y += maxStep;
        else
            location.y += distanceToGoalHorizontal;
    }
}
void tigerPushBack(point &location, const point goalLocation, const gameMap &gameMapMat)
{
    if (location.y > goalLocation.y)
    {
        if (location.x > goalLocation.x)
        {
            if ((location.x + 2) >= gameMapMat.row)
                location.x = gameMapMat.row - 1;
            else
                location.x += 2;

            if ((location.y + 2) >= gameMapMat.col)
                location.y = gameMapMat.col - 1;
            else
                location.y += 2;
        }
        else if (location.x < goalLocation.x)
        {
            if ((location.x - 2) < 0)
                location.x = 0;
            else
                location.x -= 2;

            if ((location.y + 2) >= gameMapMat.col)
                location.y = gameMapMat.col - 1;
            else
                location.y += 2;
        }
        else
        {
            if ((location.y + 2) >= gameMapMat.col)
                location.y = gameMapMat.col - 1;
            else
                location.y += 2;
        }
    }
    else if (location.y < goalLocation.y)
    {
        if (location.x > goalLocation.x)
        {
            if ((location.x + 2) >= gameMapMat.row)
                location.x = gameMapMat.row - 1;
            else
                location.x += 2;

            if ((location.y - 2) < 0)
                location.y = 0;
            else
                location.y -= 2;
        }
        else if (location.x < goalLocation.x)
        {
            if ((location.x - 2) < 0)
                location.x = 0;
            else
                location.x -= 2;

            if ((location.y - 2) < 0)
                location.y = 0;
            else
                location.y -= 2;
        }
        else
        {
            if ((location.y - 2) < 0)
                location.y = 0;
            else
                location.y -= 2;
        }
    }
    else
    {
        if (location.x > goalLocation.x)
        {
            if ((location.x + 2) >= gameMapMat.row)
                location.x = gameMapMat.row - 1;
            else
                location.x += 2;
        }
        else if (location.x < goalLocation.x)
        {
            if ((location.x - 2) < 0)
                location.x = 0;
            else
                location.x -= 2;
        }
    }
}
void defaultMove(point &location, point &startLocation, string ID, const gameMap &gameMapMat)
{
    gameMapMat.mapMat[startLocation.x][startLocation.y] = removeZodiac(gameMapMat.mapMat[startLocation.x][startLocation.y], string(ID));
    if (gameMapMat.mapMat[location.x][location.y].empty())
    {
        gameMapMat.mapMat[location.x][location.y] = ID;
    }
    else
    {
        gameMapMat.mapMat[location.x][location.y] += ID;
    }
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

zodiac::zodiac(const string &id, const point &loc) : ID(id), location(loc), status("")
{
    step = 2;
    bufferSize = 0;
}
rat::rat(const string &id, const point &loc) : zodiac(id, loc)
{
    zodiacType = "rat";
    step = 1;
}
ox::ox(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "ox"; }
tiger::tiger(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "tiger"; }
cat::cat(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "cat"; }
dragon::dragon(const string &id, const point &loc) : zodiac(id, loc)
{
    zodiacType = "dragon";
    step = 1;
}
snake::snake(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "snake"; }
horse::horse(const string &id, const point &loc) : zodiac(id, loc)
{
    zodiacType = "horse";
    step = 3;
}
goat::goat(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "goat"; }
monkey::monkey(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "monkey"; }
rooster::rooster(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "rooster"; }
dog::dog(const string &id, const point &loc) : zodiac(id, loc) { zodiacType = "dog"; }
boar::boar(const string &id, const point &loc) : zodiac(id, loc)
{
    zodiacType = "boar";
    step = 1;
}

// ================================== END OF CONSTRUCTOR ==================================

// ================================== START OF ZODIAC PRINTING FUNCTION ==================================

void zodiac::printInfo() const {}
void zodiac::printCommonInfo() const
{
    cout << zodiacType << " " << ID << " at (" << location.x << "," << location.y << ")\n";
}
void rat::printInfo() const
{
    printCommonInfo();
}
void ox::printInfo() const
{
    printCommonInfo();
}
void tiger::printInfo() const
{
    printCommonInfo();
}
void cat::printInfo() const
{
    printCommonInfo();
}
void dragon::printInfo() const
{
    printCommonInfo();
}
void snake::printInfo() const
{
    printCommonInfo();
}
void horse::printInfo() const
{
    printCommonInfo();
}
void goat::printInfo() const
{
    printCommonInfo();
}
void monkey::printInfo() const
{
    printCommonInfo();
}
void rooster::printInfo() const
{
    printCommonInfo();
}
void dog::printInfo() const
{
    printCommonInfo();
}
void boar::printInfo() const
{
    printCommonInfo();
}

// ================================== END OF ZODIAC PRINTING FUNCTION ==================================

// ================================== START OF LOCATION COMPUTE FUNCTION ==================================

void zodiac::computeLocation(const point &goalLocation, const gameMap &gameMapMat) {}
void rat::computeLocation(const point &goalLocation, const gameMap &gameMapMat) {}
void ox::computeLocation(const point &goalLocation, const gameMap &gameMapMat)
{
    int maxStep = this->step + this->bufferSize;

    if (findObstacles(gameMapMat.mapMat[this->location.x][this->location.y], 'W'))
        maxStep = 3 + this->bufferSize;
    if (findObstacles(gameMapMat.mapMat[this->location.x][this->location.y], 'O'))
        maxStep = 1;

    computeOxBoarMonkey(this->location, goalLocation, maxStep, gameMapMat);
}
void tiger::computeLocation(const point &goalLocation, const gameMap &gameMapMat)
{
    int maxStep = this->step + this->bufferSize;
    defaultComputeLocation(this->location, this->startLocation, goalLocation, maxStep, this->status, this->zodiacType, gameMapMat);
}
void cat::computeLocation(const point &goalLocation, const gameMap &gameMapMat)
{
    int maxStep = this->step + this->bufferSize;
    defaultComputeLocation(this->location, this->startLocation, goalLocation, maxStep, this->status, this->zodiacType, gameMapMat);
}
void dragon::computeLocation(const point &goalLocation, const gameMap &gameMapMat)
{
    int maxStep = this->step + this->bufferSize;
    int distanceToGoalHorizontal = goalDistance(this->location.y, goalLocation.y);
    int distanceToGoalVertical = goalDistance(this->location.x, goalLocation.x);
    int distanceToMove = min(distanceToGoalHorizontal, distanceToGoalVertical);

    if (this->location.y > goalLocation.y)
    {
        if (this->location.x > goalLocation.x)
        {
            for (int i = 1; i <= maxStep; i++)
            {
                if (findObstacles(gameMapMat.mapMat[this->location.x - i][this->location.y - i], 'O'))
                    distanceToMove = i - 1;
            }
            if (distanceToMove > maxStep)
            {
                this->location.y -= maxStep;
                this->location.x -= maxStep;
            }
            else if (distanceToMove > 0)
            {
                this->location.y -= distanceToMove;
                this->location.x -= distanceToMove;
            }
            else
                defaultComputeLocation(this->location, this->startLocation, goalLocation, maxStep, this->status, this->zodiacType, gameMapMat);
        }
        else if (this->location.x < goalLocation.x)
        {
            for (int i = 1; i <= maxStep; i++)
            {
                if (findObstacles(gameMapMat.mapMat[this->location.x + i][this->location.y - i], 'O'))
                    distanceToMove = i - 1;
            }
            if (distanceToMove > maxStep)
            {
                this->location.y -= maxStep;
                this->location.x += maxStep;
            }
            else if (distanceToMove > 0)
            {
                this->location.y -= distanceToMove;
                this->location.x += distanceToMove;
            }
            else
                defaultComputeLocation(this->location, this->startLocation, goalLocation, maxStep, this->status, this->zodiacType, gameMapMat);
        }
        else
        {
            defaultComputeLocation(this->location, this->startLocation, goalLocation, maxStep, this->status, this->zodiacType, gameMapMat);
        }
    }
    else if (this->location.y < goalLocation.y)
    {
        if (this->location.x > goalLocation.x)
        {
            for (int i = 1; i <= maxStep; i++)
            {
                if (findObstacles(gameMapMat.mapMat[this->location.x - i][this->location.y + i], 'O'))
                    distanceToMove = i - 1;
            }
            if (distanceToMove > maxStep)
            {
                this->location.y += maxStep;
                this->location.x -= maxStep;
            }
            else if (distanceToMove > 0)
            {
                this->location.y += distanceToMove;
                this->location.x -= distanceToMove;
            }
            else
                defaultComputeLocation(this->location, this->startLocation, goalLocation, maxStep, this->status, this->zodiacType, gameMapMat);
        }
        else if (this->location.x < goalLocation.x)
        {
            for (int i = 1; i <= maxStep; i++)
            {
                if (findObstacles(gameMapMat.mapMat[this->location.x + i][this->location.y + i], 'O'))
                    distanceToMove = i - 1;
            }
            if (distanceToMove > maxStep)
            {
                this->location.y += maxStep;
                this->location.x += maxStep;
            }
            else if (distanceToMove > 0)
            {
                this->location.y += distanceToMove;
                this->location.x += distanceToMove;
            }
            else
                defaultComputeLocation(this->location, this->startLocation, goalLocation, maxStep, this->status, this->zodiacType, gameMapMat);
        }
        else
        {
            defaultComputeLocation(this->location, this->startLocation, goalLocation, maxStep, this->status, this->zodiacType, gameMapMat);
        }
    }
    else
    {
        if (this->location.x > goalLocation.x)
        {
            defaultComputeLocation(this->location, this->startLocation, goalLocation, maxStep, this->status, this->zodiacType, gameMapMat);
        }
        else if (this->location.x < goalLocation.x)
        {
            defaultComputeLocation(this->location, this->startLocation, goalLocation, maxStep, this->status, this->zodiacType, gameMapMat);
        }
    }
}
void snake::computeLocation(const point &goalLocation, const gameMap &gameMapMat)
{
    int maxStep = this->step + this->bufferSize;
    defaultComputeLocation(this->location, this->startLocation, goalLocation, maxStep, this->status, this->zodiacType, gameMapMat);
}
void horse::computeLocation(const point &goalLocation, const gameMap &gameMapMat)
{
    int maxStep = this->step + this->bufferSize;
    defaultComputeLocation(this->location, this->startLocation, goalLocation, maxStep, this->status, this->zodiacType, gameMapMat);
}
void goat::computeLocation(const point &goalLocation, const gameMap &gameMapMat)
{
    int maxStep = this->step + this->bufferSize;
    defaultComputeLocation(this->location, this->startLocation, goalLocation, maxStep, this->status, this->zodiacType, gameMapMat);
}
void monkey::computeLocation(const point &goalLocation, const gameMap &gameMapMat)
{
    int maxStep = this->step + this->bufferSize;

    if (findObstacles(gameMapMat.mapMat[this->location.x][this->location.y], 'T'))
        maxStep = 4 + this->bufferSize;
    if (findObstacles(gameMapMat.mapMat[this->location.x][this->location.y], 'O'))
        maxStep = 1;

    if (findObstacles(gameMapMat.mapMat[this->location.x][this->location.y], 'T'))
        computeOxBoarMonkey(this->location, goalLocation, maxStep, gameMapMat);
    else
        defaultComputeLocation(this->location, this->startLocation, goalLocation, maxStep, this->status, this->zodiacType, gameMapMat);
}
void rooster::computeLocation(const point &goalLocation, const gameMap &gameMapMat) {}
void dog::computeLocation(const point &goalLocation, const gameMap &gameMapMat)
{
    int maxStep = this->step + this->bufferSize;
    defaultComputeLocation(this->location, this->startLocation, goalLocation, maxStep, this->status, this->zodiacType, gameMapMat);
}
void boar::computeLocation(const point &goalLocation, const gameMap &gameMapMat)
{
    int maxStep = this->step + this->bufferSize;

    if (findObstacles(gameMapMat.mapMat[this->location.x][this->location.y], 'O'))
        maxStep = 1;

    computeOxBoarMonkey(this->location, goalLocation, maxStep, gameMapMat);
}

// ================================== END OF LOCATION COMPUTE FUNCTION ==================================

// ================================== START OF MOVE FUNCTION ==================================

void zodiac::move(const point &goalLocation, const gameMap &gameMapMat) {}
void rat::move(const point &goalLocation, const gameMap &gameMapMat) {}
void ox::move(const point &goalLocation, const gameMap &gameMapMat)
{
    int distanceToGoalHorizontal = goalDistance(this->startLocation.y, goalLocation.y);
    int distanceToGoalVertical = goalDistance(this->startLocation.x, goalLocation.x);
    gameMapMat.mapMat[this->startLocation.x][this->startLocation.y] = removeZodiac(gameMapMat.mapMat[this->startLocation.x][this->startLocation.y], string(this->ID));
    if (distanceToGoalHorizontal < distanceToGoalVertical)
    {
        if (this->location.x > this->startLocation.x)
        {
            for (int i = this->startLocation.x; i < this->location.x; i++)
                gameMapMat.mapMat[i][this->location.y] = removeStone(gameMapMat.mapMat[i][this->location.y]);
        }
        else
        {
            for (int i = this->startLocation.x; i > this->location.x; i--)
                gameMapMat.mapMat[i][this->location.y] = removeStone(gameMapMat.mapMat[i][this->location.y]);
        }
    }
    else
    {
        if (this->location.y > this->startLocation.y)
        {
            for (int i = this->startLocation.y; i < this->location.y; i++)
                gameMapMat.mapMat[this->location.x][i] = removeStone(gameMapMat.mapMat[this->location.x][i]);
        }
        else
        {
            for (int i = this->startLocation.y; i > this->location.y; i--)
                gameMapMat.mapMat[this->location.x][i] = removeStone(gameMapMat.mapMat[this->location.x][i]);
        }
    }
    if (gameMapMat.mapMat[this->location.x][this->location.y].empty())
    {
        gameMapMat.mapMat[this->location.x][this->location.y] = this->ID;
    }
    else
    {
        gameMapMat.mapMat[this->location.x][this->location.y] = removeStone(gameMapMat.mapMat[this->location.x][this->location.y]);
        gameMapMat.mapMat[this->location.x][this->location.y] += this->ID;
    }
}
void tiger::move(const point &goalLocation, const gameMap &gameMapMat)
{
    defaultMove(this->location, this->startLocation, string(this->ID), gameMapMat);
}
void cat::move(const point &goalLocation, const gameMap &gameMapMat)
{
    defaultMove(this->location, this->startLocation, string(this->ID), gameMapMat);
}
void dragon::move(const point &goalLocation, const gameMap &gameMapMat)
{
    defaultMove(this->location, this->startLocation, string(this->ID), gameMapMat);
}
void snake::move(const point &goalLocation, const gameMap &gameMapMat)
{
    defaultMove(this->location, this->startLocation, string(this->ID), gameMapMat);
}
void horse::move(const point &goalLocation, const gameMap &gameMapMat)
{
    int distanceToGoalHorizontal = goalDistance(this->startLocation.y, goalLocation.y);
    int distanceToGoalVertical = goalDistance(this->startLocation.x, goalLocation.x);
    gameMapMat.mapMat[this->startLocation.x][this->startLocation.y] = removeZodiac(gameMapMat.mapMat[this->startLocation.x][this->startLocation.y], string(this->ID));
    if (distanceToGoalHorizontal < distanceToGoalVertical)
    {
        if (this->location.x > this->startLocation.x)
        {
            for (int i = this->startLocation.x; i < this->location.x; i++)
            {
                if (findObstacles(gameMapMat.mapMat[i][this->location.y], 'S'))
                    this->step = 1;
            }
        }
        else
        {
            for (int i = this->startLocation.x; i > this->location.x; i--)
            {
                if (findObstacles(gameMapMat.mapMat[i][this->location.y], 'S'))
                    this->step = 1;
            }
        }
    }
    else
    {
        if (this->location.y > this->startLocation.y)
        {
            for (int i = this->startLocation.y; i < this->location.y; i++)
            {
                if (findObstacles(gameMapMat.mapMat[this->location.x][i], 'S'))
                    this->step = 1;
            }
        }
        else
        {
            for (int i = this->startLocation.y; i > this->location.y; i--)
            {
                if (findObstacles(gameMapMat.mapMat[this->location.x][i], 'S'))
                    this->step = 1;
            }
        }
    }
    if (gameMapMat.mapMat[this->location.x][this->location.y].empty())
    {
        gameMapMat.mapMat[this->location.x][this->location.y] = this->ID;
    }
    else
    {
        gameMapMat.mapMat[this->location.x][this->location.y] += this->ID;
    }
}
void goat::move(const point &goalLocation, const gameMap &gameMapMat)
{
    defaultMove(this->location, this->startLocation, string(this->ID), gameMapMat);
}
void monkey::move(const point &goalLocation, const gameMap &gameMapMat)
{
    defaultMove(this->location, this->startLocation, string(this->ID), gameMapMat);
}
void rooster::move(const point &goalLocation, const gameMap &gameMapMat) {}
void dog::move(const point &goalLocation, const gameMap &gameMapMat)
{
    defaultMove(this->location, this->startLocation, string(this->ID), gameMapMat);
}
void boar::move(const point &goalLocation, const gameMap &gameMapMat)
{
    gameMapMat.mapMat[this->startLocation.x][this->startLocation.y] = removeZodiac(gameMapMat.mapMat[this->startLocation.x][this->startLocation.y], string(this->ID));
    if (gameMapMat.mapMat[this->location.x][this->location.y].empty())
    {
        gameMapMat.mapMat[this->location.x][this->location.y] = this->ID;
    }
    else
    {
        gameMapMat.mapMat[this->location.x][this->location.y] = removeWater(gameMapMat.mapMat[this->location.x][this->location.y]);
        gameMapMat.mapMat[this->location.x][this->location.y] = removeStone(gameMapMat.mapMat[this->location.x][this->location.y]);
        gameMapMat.mapMat[this->location.x][this->location.y] += this->ID;
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
zodiac *zoList::operator[](int i)
{
    if (i >= 0 && i < size)
    {
        return zList[i];
    }
    return nullptr;
}

// ================================== END OF ZOLIST INITIALIZE ==================================

// ================================== START OF GAME INITIALIZE ==================================

Game::Game(const gameMap &m) : mapMat(m) {}
void Game::addZo(zodiac *k)
{
    zList.add(k);
    int x = k->location.x;
    int y = k->location.y;
    if (mapMat.mapMat[x][y].empty())
        mapMat.mapMat[x][y] = k->ID;
    else
        mapMat.mapMat[x][y] += k->ID;
}
void Game::startGame(point goalLocation, bool printMapFlag = 0)
{
    cout << "GAME START" << endl;
    mapMat[goalLocation.x][goalLocation.y] = 'G';
    mapMat.printMap();
    zodiac *winnerZodiac = nullptr;
    int turn = 0;
    while (true)
    {
        turn++;
        cout << "TURN " << turn << endl;

        bool allStuck = true;
        bool winnerFound = false;

        // set start location to current location when start game
        for (int i = 0; i < zList.size; i++)
        {
            zodiac *setStartLocation = zList[i];
            setStartLocation->startLocation.x = zList[i]->location.x;
            setStartLocation->startLocation.y = zList[i]->location.y;
        }

        // tiger effect
        for (int i = 0; i < zList.size; i++)
        {
            zodiac *tiger = zList[i];
            if (tiger->zodiacType == "tiger")
            {
                for (int i = 0; i < zList.size; i++)
                {
                    zodiac *otherZodiac = zList[i];
                    if ((otherZodiac->zodiacType != "tiger") && (otherZodiac->zodiacType != "cat") && (otherZodiac->location.x == tiger->location.x) && (otherZodiac->location.y == tiger->location.y))
                    {
                        tigerPushBack(otherZodiac->location, goalLocation, mapMat);
                        mapMat[otherZodiac->startLocation.x][otherZodiac->startLocation.y] = removeZodiac(mapMat[otherZodiac->startLocation.x][otherZodiac->startLocation.y], string(otherZodiac->ID));
                        otherZodiac->startLocation.x = otherZodiac->location.x;
                        otherZodiac->startLocation.y = otherZodiac->location.y;
                        if (otherZodiac->zodiacType == "dog" && otherZodiac->bufferSize == 0)
                        {
                            otherZodiac->bufferSize++;
                        }
                        if ((otherZodiac->zodiacType == "snake") && (tiger->status == ""))
                        {
                            tiger->status = "poisoned";
                        }
                    }
                }
            }
        }

        // dog effect
        for (int i = 0; i < zList.size; i++)
        {
            zodiac *dog = zList[i];
            if (dog->zodiacType == "dog")
            {
                for (int i = 0; i < zList.size; i++)
                {
                    zodiac *otherZodiac = zList[i];
                    if ((otherZodiac->location.x == dog->location.x) && (otherZodiac->location.y == dog->location.y) && (otherZodiac != dog))
                    {
                        if (dog->bufferSize == 0)
                            dog->bufferSize++;
                        if ((otherZodiac->zodiacType != "cat") && (otherZodiac->bufferSize == 0))
                            otherZodiac->bufferSize++;
                    }
                }
            }
        }

        // snake effect
        for (int i = 0; i < zList.size; i++)
        {
            zodiac *snake = zList[i];
            if (snake->zodiacType == "snake")
            {
                for (int i = 0; i < zList.size; i++)
                {
                    zodiac *otherZodiac = zList[i];
                    if ((otherZodiac->location.x == snake->location.x) && (otherZodiac->location.y == snake->location.y) && (otherZodiac != snake))
                    {
                        if (otherZodiac->zodiacType != "cat" && otherZodiac->status == "")
                            otherZodiac->status = "poisoned";
                    }
                }
            }
        }

        // compute the location of all zodiacs before move
        for (int i = 0; i < zList.size; i++)
        {
            zodiac *currentZodiac = zList[i];
            if (currentZodiac->status != "poisoned")
                currentZodiac->computeLocation(goalLocation, mapMat);
        }

        // move
        for (int i = 0; i < zList.size; i++)
        {
            zodiac *currentZodiac = zList[i];
            currentZodiac->move(goalLocation, mapMat);
            if (currentZodiac->location.x == goalLocation.x && currentZodiac->location.y == goalLocation.y)
            {
                if (!winnerFound)
                {
                    winnerFound = true;
                    winnerZodiac = currentZodiac;
                }
            }
        }

        // reset
        for (int i = 0; i < zList.size; i++)
        {
            zodiac *currentZodiac = zList[i];
            currentZodiac->bufferSize = 0;
            if (currentZodiac->status == "poisoned")
                currentZodiac->status = "";
        }

        // print result of each turn
        for (int i = 0; i < zList.size; i++)
        {
            zodiac *currentZodiac = zList[i];
            cout << currentZodiac->zodiacType << " " << currentZodiac->ID << " at (" << currentZodiac->location.x << "," << currentZodiac->location.y << ") move from (" << currentZodiac->startLocation.x << "," << currentZodiac->startLocation.y << ")\n";
        }
        if (printMapFlag)
        {
            mapMat.printMap();
        }
        for (int i = 0; i < zList.size; i++)
        {
            zodiac *currentZodiac = zList[i];
            if (currentZodiac->status != "Stuck")
            {
                allStuck = false;
            }
        }
        if (allStuck || winnerFound)
        {
            if (winnerFound)
            {
                cout << "########RESULT#########\nCongratulations to the winner ";
                winnerZodiac->printInfo();
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