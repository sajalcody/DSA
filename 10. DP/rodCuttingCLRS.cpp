#include <iostream>
#include <string> // memset
using namespace std;

// Recursive Approach => T:O(2ⁿ)
int maxProfitRecursive(int rodLength, int a[100]){ 
    // cout << "maxProfit ("<<rodLength<<")" << " = "; // To see how many repeated calls are done.
    if(rodLength ==0){
        // cout << "0\n";
        return 0;
    }
    int profit = 0, newProfit=0;
    for(int i = 1; i <= rodLength; i++){
        newProfit = a[i-1] + maxProfitRecursive(rodLength - i, a);
        profit = newProfit > profit ? newProfit : profit;
    }
    // cout << profit << endl;
    return profit;
}

/* Top Down Dp with Memoization => T:O(n²),  S:O(n)
-> Adv: Does not actually recurse to examine all possible subproblems
-> Depth First search of the Dependency graph
*/
int profitArr[100];
int maxProfitTopDown(int rodLength, int a[100]){ 
    cout << "maxProfit ("<<rodLength<<")" << " = "; // To see how many repeated calls are done.
    if(profitArr[rodLength] >= 0)
        return profitArr[rodLength];
    if(rodLength ==0)
        return 0;
    int profit = 0, newProfit=0;
    for(int i = 1; i <= rodLength; i++){
            newProfit = a[i-1] + maxProfitRecursive(rodLength - i, a);
        profit = newProfit > profit ? newProfit : profit;
    }
    profitArr[rodLength]=profit;
    return profit;
}

/* Bottom Up DP method => T:O(n²),  S:O(n)
-> Adv: Has better constant factors as it has less overhead for procedure calls.
-> Reverse Topological Sort of the dependency graph
*/
int maxProfitBottomUp(int rodLength, int a[100]){
    int profit[rodLength+1];
    for(int i = 1; i <= rodLength; i++){
        profit[i]=a[i-1];
        for(int j = 1; j <= i/2; j++){ // i/2 as (1,4) is same as (4,1)
            profit[i] = profit[j]+profit[i-j] > profit[i] ? profit[j]+profit[i-j]:profit[i];
        }
    }
    return profit[rodLength];
}

// It prints the desired cuts also.
int maxProfitBottomUpExt(int rodLength, int a[100]){
    int profit[rodLength+1], sol[rodLength+1];
    for(int i = 1; i <= rodLength; i++){
        profit[i]=a[i-1];
        sol[i]=i;
        for(int j = 1; j <= i/2; j++){ // i/2 as (1,4) is same as (4,1)
            if(profit[j]+profit[i-j] > profit[i]) {
                profit[i]=profit[j]+profit[i-j];
                sol[i]=j;
            }
        }
        // cout << sol[i] << " ";
    }
    int n=rodLength;
    cout << "Soln is: ";
    while(n > 0){
        cout << sol[n] << " ";
        n -= sol[n];
    }
    cout << endl;
    return profit[rodLength];
}

int main(){
    int t, n, rodLength;
    cin >> t;
    while(t--){
        cin >> rodLength >> n;
        memset(profitArr,-1,sizeof(profitArr));
        int a[n];
        for(int i=0; i < n; i++)
            cin >> a[i];
        cout << maxProfitRecursive(rodLength, a) << endl;
        cout << maxProfitBottomUp(rodLength, a) << endl;
        cout << maxProfitTopDown(rodLength, a) << endl;
        cout << maxProfitBottomUpExt(rodLength, a) << endl;
    }
    return 0;
}


/*Sample test case
4 10
1 5 8 9 10 17 17 20 24 30
Ans: 10 (break into 2,2)
*/