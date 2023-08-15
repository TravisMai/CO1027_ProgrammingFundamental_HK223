#ifndef LIB_H
#define LIB_H
#include <string>
#include <iomanip>
using namespace std;

class gameMap
{
private:
    string **mapMat;
    int row;
    int col;

    void printTopHorizontalBorder();

    void printBottomLine();

    void printTopHorizontalCellBorder();

public:
    gameMap(string **inputMat, int r, int c);

    string *&operator[](int i);

    void printMap();

    ~gameMap();
};

struct point
{
    int x;
    int y;
    point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
};

class zodiac
{
protected:
    string ID;
    point location;
    string status;
    void printCommonInfo() const;

public:
    zodiac(const string &id, const point &loc);
    virtual ~zodiac() {}

    virtual void printInfo() const = 0;
    virtual void move(const point &goalLocation, const gameMap &gameMap);
};

class rat : public zodiac
{
public:
    rat(const std::string &id, const point &loc);
    void printInfo() const override;
    void move(const point &goalLocation, const gameMap &gameMap) override;
};

class ox : public zodiac
{
public:
    ox(const std::string &id, const point &loc);
    void printInfo() const override;
    void move(const point &goalLocation, const gameMap &gameMap) override;
};

class tiger : public zodiac
{
public:
    tiger(const std::string &id, const point &loc);
    void printInfo() const override;
    void move(const point &goalLocation, const gameMap &gameMap) override;
};

class cat : public zodiac
{
public:
    cat(const std::string &id, const point &loc);
    void printInfo() const override;
    void move(const point &goalLocation, const gameMap &gameMap) override;
};

class dragon : public zodiac
{
public:
    dragon(const std::string &id, const point &loc);
    void printInfo() const override;
    void move(const point &goalLocation, const gameMap &gameMap) override;
};

class snake : public zodiac
{
public:
    snake(const std::string &id, const point &loc);
    void printInfo() const override;
    void move(const point &goalLocation, const gameMap &gameMap) override;
};

class horse : public zodiac
{
public:
    horse(const std::string &id, const point &loc);
    void printInfo() const override;
    void move(const point &goalLocation, const gameMap &gameMap) override;
};

class goat : public zodiac
{
public:
    goat(const std::string &id, const point &loc);
    void printInfo() const override;
    void move(const point &goalLocation, const gameMap &gameMap) override;
};

class monkey : public zodiac
{
public:
    monkey(const std::string &id, const point &loc);
    void printInfo() const override;
    void move(const point &goalLocation, const gameMap &gameMap) override;
};

class rooster : public zodiac
{
public:
    rooster(const std::string &id, const point &loc);
    void printInfo() const override;
    void move(const point &goalLocation, const gameMap &gameMap) override;
};

class dog : public zodiac
{
public:
    dog(const std::string &id, const point &loc);
    void printInfo() const override;
    void move(const point &goalLocation, const gameMap &gameMap) override;
};

class boar : public zodiac
{
public:
    boar(const std::string &id, const point &loc);
    void printInfo() const override;
    void move(const point &goalLocation, const gameMap &gameMap) override;
};

#endif // LIB_H