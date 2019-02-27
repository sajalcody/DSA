#include <iostream>
using namespace std;

int main(){
  int x;
  cout << &x << " " << x << endl;
  int *p = &x;
  cout << "From pointer's view \n";
  cout << p << " " << *p << " " << &p  << " " << **(&p);
  return 0;
}