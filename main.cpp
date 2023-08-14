#include <iostream>
using namespace std;

class gameMap
{
private:
    string **mapMat;
    int row;
    int col;

    void printTopHorizontalBorder()
    {
        cout << ' ';
        for (int j = 0; j < (7 * col + col - 1); j++)
        {
            cout << '_';
        }
        cout << '\n';
    }

    void printBottomLine()
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

    void printTopHorizontalCellBorder()
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

public:
    gameMap(string **inputMat, int r, int c) : mapMat(inputMat), row(r), col(c) {}

    string *&operator[](int i)
    {
        return mapMat[i];
    }

    void printMap()
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
                        cout << string(7, ' ');
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
        printBottomLine();
    }

    ~gameMap()
    {
        for (int i = 0; i < row; i++)
        {
            delete[] mapMat[i];
        }
        delete[] mapMat;
    }
};

int main()
{
    string tempMap[50][50] = {
        {"", "", "QWERt90-9", "", "S"},
        {"", "W", "", "", "S"},
        {"W", "S", "", "", "S"},
        {"W", "S", "", "", "S"},
        {"W", "S", "", "", ""}};
    int r = 5;
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
    gMap.printMap();

    return 0;
}