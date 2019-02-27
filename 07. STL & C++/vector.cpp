#include <iostream>
#include <vector> // vector (COMPILE CMD: g++ prog.cpp --std=c++11)
#include <utility> // pair
#include <functional> // greater
using namespace std;

void printVector(vector <int> v){
    for(int x: v)
        cout << x << " ";
    cout << endl;
}

void printVectorPair(vector< pair <int, int> > v){
    cout << "Printing your vector\n";
    for(auto p : v)
        cout << p.first << " " << p.second << endl;
}

void vector2D(){
    int m=2,n=3;
    vector<vector<int> > vec( n , vector<int> (m, 0));
}

/* Sorting functions for vector of pair */

bool sortBySecond(pair <int,int> a, pair <int,int> b){
    return a.second < b.second;
}

bool sortBySecondThenFirst(pair <int,int> a, pair <int,int> b){
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

bool sortByFirstDesc(pair <int,int> a, pair <int,int> b){
    if (a.first != b.first)
        return a.first > b.first;
    return a.second > b.second;

}

void vectorofPair(){
    vector< pair <int, int> > v;
    v.push_back(make_pair(1,-1)); // With push 
    v.emplace_back(3,10); // With emplace, contructor is called internally.
    v.emplace_back(2,-2);
    v.emplace_back(4,-4);
    v.emplace_back(6,-6);
    v.emplace_back(3,-3);
    v.emplace_back(3,-7);
    v.emplace_back(0,-6);

    // Accessing using auto
    cout << "Accessing using auto\n";
    for(auto p : v)
        cout << p.first << " " << p.second << endl;

    // Accessing using index
    // cout <<"Accessing using index\n";
    // for(int i = 0; i < v.size(); i++)
    //     cout << v[i].first << " " << v[i].second << endl;

    //Soring a vector of Pairs
    vector< pair <int, int> > vnew(v.begin(), v.end());

    /*1. Sort() sorts the vector in ascending order by first ele of pair
          and for same first element then by second element*/
    sort(vnew.begin(), vnew.end());
    printVectorPair(vnew);

    /*2. Sorting in ascending order by second element
        without considering first element*/
    sort(vnew.begin(), vnew.end(), sortBySecond);
    printVectorPair(vnew);

    /*2. Sorting in ascending order by second element
         considering first element if second is same*/
    sort(vnew.begin(), vnew.end(), sortBySecondThenFirst);
    printVectorPair(vnew);

    /*2. Sorting in descending order by first element
         considering second element if first is same*/
    sort(vnew.begin(), vnew.end(), sortByFirstDesc);
    printVectorPair(vnew);


}
void vectorByRef(vector <int> &v){ // Passing Vector By Reference
    v.push_back(-1);
}

void simpleVector(){
int n=5, defaultValue = 1;
    //int arr[n] = {1,2,3,2,1}; // ERROR : variable-sized object may not be initialized
    int arr[] = {1,2,3,2,1};

    // Declarations with initialisations
    vector <int> vDefault; //empty vector
    vector <int> vSize(n); // Vector of size n; equiv to int a[n]; (on printing prints 0 for all values)
    vector <int> vSizeVal(n, defaultValue); // vector of size n, all values set to defaultValue. equiv to int a[n]; memset (a, defaultValue, sizeof(a));
    vector <int> vSizeAgain(n); // to check whether printing 0 by default or not.
    vector <int> vVals {1,2,3,4}; //vector with vaues given in braces
    vector <int> vFromVector (vSizeVal.begin(), vSizeVal.end()); // a copy of vector vSizeVal
    vector <int> vFromVectorWithSize (vSizeVal.begin(), vSizeVal.begin() + 3); // a copy of vector vSizeVal but till size 3
    vector <int> vFromArray (arr, arr + n); // a copy of array arr till n

    // Accessing vector

    // Using iterator
    // vector <int> :: iterator it;
    // for(it = vVals.begin(); it != vVals.end(); it++)
    //     cout << *it << " " ;

    // Using auto with colon
    for(auto x : vVals)
        cout << x << " ";
    cout << endl;

    //By default vector is passed by reference
   vectorByRef(vVals);
   printVector(vVals);

    printVector(vFromArray);
    // Sorting in ascending order
   sort(vFromArray.begin(), vFromArray.end());
   printVector(vFromArray);

    // Sorting in descending order
   sort(vFromArray.begin(), vFromArray.end(), greater <int> ());
   printVector(vFromArray);

}
int main(){
    // vectorofPair();
    simpleVector();
    return 0;
}