#include <iostream>
using namespace std;

class Parent{

    int privateV;
    public:
    int idP;
};

class Child : public Parent{
    public:
    int idC;
};

int main(){
    Child c;
    c.privateV = 1;
    c.idP = 1;
    c.idC = 2;
    cout << c.idP << " " << c.idC;
}