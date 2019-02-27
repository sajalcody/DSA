#include <iostream>
#include <vector>
using namespace std;

/* ALL K valued STRINGS OF N BITS
-> for n bits, at any position there are k possible values 0, 1, 2....,k-1.
   So, k for every bits => k*k*...n times
   Total combinations possible = kⁿ
T:O(kⁿ), 
Can start filling 1 combination either from beg or end
*/

void getCombinations(int n, vector<vector<int> > &comb, int k, int i, vector <int> &currentC){
    if(i == n)
        comb.push_back(currentC);
    else{
        for(int value = 0; value < k; value++){
            currentC[i]=value;
            getCombinations(n, comb, k, i+1, currentC);
        }
    }
}

int main(){
    int n, k;
    vector<vector<int> > comb;
    cin >> n >> k;
    vector <int> c(n);
    getCombinations(n, comb, k, 0, c);
    for(auto combination : comb){
        for(int x : combination)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}