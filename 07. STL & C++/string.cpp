#include <iostream>
#include <string>
using namespace std;

int main (){
    
    string s = "This is a very long string, with spaces and special characters.";
    cout << s << endl; 
    // substr O(n)
    // string s1 = s.substr(6, 5); // Substring from index 6 and take 5 characters and if 5 exceeds the length then take till last character
    // cout << s1 << endl;
    // string s2 = s.substr(6); //from index 6 to last character (default index 0)
    // cout << s2 << endl;
    // string s3 = s.substr(); // from index 0 to last character i.e. entire string 
    // cout << s3 << endl;

    // find (TODO: implement matching a substring in a given string)

    string sLen(5,'*');
    cout << sLen << endl;
    sLen[0]='S';
    cout << sLen << endl;
    sLen = "#$#$#";
    cout << sLen << endl;
    sLen = "SAJAL AGR";
    cout << sLen << endl;
    return 0;
}