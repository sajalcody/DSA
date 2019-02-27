#include <iostream>
#include <string>
using namespace std;

void stringBits(string s, int n){
    if (n == 0)
    {
        cout << s << endl;
        return;
    }
    stringBits(s + "0", n - 1);
    stringBits(s + "1", n - 1);
    return;
}
int main(){
    int n;
    string s;
    cin >> n;
    stringBits("", n);
    return 0;
}