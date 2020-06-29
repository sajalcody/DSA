#include <iostream>
using namespace std;

/*
Given two points (x1,y1) (x2,y2),
return equation of line passing through these points.

Equation of a line:
y = mx + b
where: m = (y2-y1)/(x2-x1)
b can be calulcated by putting x = x1, y = y1 in above eq.
*/

/*
Given 3 points, determine, they belong to same line or not.

Form eq from any two points and satisy the third point
*/

bool formLine(int x1, int y1, int x2, int y2, int x3, int y3){
    if (x1 == x2)
        return x1 == x3;
    double yCalc = ((y2-y1)/(x2-x1))*x3 + (y1 - ((y2-y1)/(x2-x1))*x1);
    return yCalc == (double)y3;
}

int main(){
    int x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << formLine(x1,y1,x2,y2,x3,y3);
    return 0;
}