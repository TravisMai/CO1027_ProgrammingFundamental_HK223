#include <iostream>
#include "lib.h"
using namespace std;

int main()
{

    string tempMap[50][50]=
{   {"","","","",""},
    {"","S","S","",""},
    {"","S","O","",""},
    {"S","","","",""},
    {"","","","",""}};
int r=5;
int c=5;
string **Map=new string*[r];
for(int i=0;i<r;i++){
    Map[i]=new string[c];
    for(int j=0;j<c;j++){
        Map[i][j]=tempMap[i][j];
    }
}
gameMap gMap(Map,r,c);
Game a(gMap);
zodiac* e1=new snake("E1",point(2,2));
zodiac* e2=new snake("E2",point(2,2));
zodiac* t3=new tiger("R3",point(2,2));
a.addZo(e1);
a.addZo(e2);
a.addZo(t3);
a.startGame(point(4,2), 1);

    return 0;
}