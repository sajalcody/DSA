#include <iostream>
#include <vector>
using namespace std;

/* ALL BINARY STRINGS OF N BITS
-> for n bits, at any position there are two possible values 0 or 1.
   So, 2 for every bits => 2*2*...n times
   Total combinations possible = 2ⁿ
T:O(2ⁿ), 
Can start filling 1 combination either from beg or end
*/

void getCombinations(int n, vector<vector<int> > &comb, int i, vector <int> &currentC){
    if(i == n)
        comb.push_back(currentC);
    else{
        currentC[i]=0;
        getCombinations(n, comb, i+1, currentC);
        currentC[i]=1;
        getCombinations(n, comb, i+1, currentC);
    }
}

int main(){
    int n;
    vector<vector<int> > comb;
    cin >> n;
    vector <int> c(n);
    getCombinations(n, comb, 0, c);
    for(auto combination : comb){
        for(int x : combination)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}