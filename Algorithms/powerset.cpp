#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void subset(vector<int>& arr, int index, vector<int>& subSet, vector<vector<int> >& powerSet){
    powerSet.push_back(subSet);
    for (int i = index; i < arr.size(); i++){
        subSet.push_back(arr[i]);
        subset(arr, i + 1, subSet, powerSet);
        subSet.pop_back();

    }
}


vector<vector<int> > subsetUtils(vector<int>& arr){
    vector<int> subSet;
    vector<vector<int> > powerSet;

    subset(arr, 0, subSet, powerSet);
    return powerSet;
}

vector<vector<int> > subsetUtils2(vector<int>& arr){
    vector<int> subSet;
    vector<vector<int> > powerSet;
    int n = arr.size();
    for (int i = 0; i < pow(2, n); i++){
        subSet.clear();
        for (int j = 0; j < n; j++){
            if ( i & (1 << j))
                subSet.push_back(arr[j]);
        }
        powerSet.push_back(subSet);
    }
    return powerSet;
}

int main(){

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    vector<vector<int> > powerSet;
    powerSet = subsetUtils2(arr);
    for (int i = 0; i < powerSet.size(); i++){
        for (int j = 0; j < powerSet[i].size(); j++)
            cout << powerSet[i][j] << " ";
        cout << "\n";
    }
    return 0;
}