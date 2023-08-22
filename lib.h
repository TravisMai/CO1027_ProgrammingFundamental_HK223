#ifndef LIB_H
#define LIB_H
#include <string>
#include <iomanip>
using namespace std;

class gameMap
{
public:
    string **mapMat;
    int row;
    int col;

    gameMap(string **inputMat, int r, int c);
    gameMap(const gameMap &other); // copy constructor
    ~gameMap();

    void printTopHorizontalBorder();
    void printBottomLine();
    void printTopHorizontalCellBorder();
    string *&operator[](int i);
    void printMap();
};

struct point
{
    int x;
    int y;

    point() : x(0), y(0) {}
    point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
};

class zodiac
{
public:
    string ID;
    point location;
    point startLocation;
    string status;
    string zodiacType;
    int step;
    int bufferSize;

    zodiac(const string &id, const point &loc);
    virtual ~zodiac() {}

    void printCommonInfo() const;
    virtual void printInfo() const = 0;
    virtual void computeLocation(const point &goalLocation, const gameMap &gameMapMat);
    virtual void move(const point &goalLocation, const gameMap &gameMapMat);
};

class rat : public zodiac
{
public:
    rat(const std::string &id, const point &loc);
    void printInfo() const override;
    void computeLocation(const point &goalLocation, const gameMap &gameMapMat) override;
    void move(const point &goalLocation, const gameMap &gameMapMat) override;
};

class ox : public zodiac
{
public:
    ox(const std::string &id, const point &loc);
    void printInfo() const override;
    void computeLocation(const point &goalLocation, const gameMap &gameMapMat) override;
    void move(const point &goalLocation, const gameMap &gameMapMat) override;
};

class tiger : public zodiac
{
public:
    tiger(const std::string &id, const point &loc);
    void printInfo() const override;
    void computeLocation(const point &goalLocation, const gameMap &gameMapMat) override;
    void move(const point &goalLocation, const gameMap &gameMapMat) override;
};

class cat : public zodiac
{
public:
    cat(const std::string &id, const point &loc);
    void printInfo() const override;
    void computeLocation(const point &goalLocation, const gameMap &gameMapMat) override;
    void move(const point &goalLocation, const gameMap &gameMapMat) override;
};

class dragon : public zodiac
{
public:
    dragon(const std::string &id, const point &loc);
    void printInfo() const override;
    void computeLocation(const point &goalLocation, const gameMap &gameMapMat) override;
    void move(const point &goalLocation, const gameMap &gameMapMat) override;
};

class snake : public zodiac
{
public:
    snake(const std::string &id, const point &loc);
    void printInfo() const override;
    void computeLocation(const point &goalLocation, const gameMap &gameMapMat) override;
    void move(const point &goalLocation, const gameMap &gameMapMat) override;
};

class horse : public zodiac
{
public:
    horse(const std::string &id, const point &loc);
    void printInfo() const override;
    void computeLocation(const point &goalLocation, const gameMap &gameMapMat) override;
    void move(const point &goalLocation, const gameMap &gameMapMat) override;
};

class goat : public zodiac
{
public:
    goat(const std::string &id, const point &loc);
    void printInfo() const override;
    void computeLocation(const point &goalLocation, const gameMap &gameMapMat) override;
    void move(const point &goalLocation, const gameMap &gameMapMat) override;
};

class monkey : public zodiac
{
public:
    monkey(const std::string &id, const point &loc);
    void printInfo() const override;
    void computeLocation(const point &goalLocation, const gameMap &gameMapMat) override;
    void move(const point &goalLocation, const gameMap &gameMapMat) override;
};

class rooster : public zodiac
{
public:
    rooster(const std::string &id, const point &loc);
    void printInfo() const override;
    void computeLocation(const point &goalLocation, const gameMap &gameMapMat) override;
    void move(const point &goalLocation, const gameMap &gameMapMat) override;
};

class dog : public zodiac
{
public:
    dog(const std::string &id, const point &loc);
    void printInfo() const override;
    void computeLocation(const point &goalLocation, const gameMap &gameMapMat) override;
    void move(const point &goalLocation, const gameMap &gameMapMat) override;
};

class boar : public zodiac
{
public:
    boar(const std::string &id, const point &loc);
    void printInfo() const override;
    void computeLocation(const point &goalLocation, const gameMap &gameMapMat) override;
    void move(const point &goalLocation, const gameMap &gameMapMat) override;
};

class zoList
{
public:
    zodiac **zList;
    int maxSize;
    int size;

    zoList();
    ~zoList();

    void add(zodiac *newZodiac);
    zodiac *operator[](int i);
};

class Game
{
public:
    gameMap mapMat;
    zoList zList;
    point goalLocation;

    Game(const gameMap &m);
    void addZo(zodiac *k);
    void startGame(point goalLocation, bool printMapFlag);
};

#endif // LIB_H