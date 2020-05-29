#include <iostream>
#include <string>
#include <limits.h>
using namespace std;
int main(){
    string words[] = {"Tushar", "Roy", "likes", "to","code"};
    int i, j, cost[50][50], n = 5, s, w = 10, dp[50], m, k, p[50];
    for (i = 0; i < n; i++){
        s = 0;
        for (j = i; j < n; j++){
            s += words[j].length();
            //cout << s <<"\n";
            cost[i][j] = (w-s) >= 0 ? (w-s) * (w - s) : -1;
            s += 1;
            cout << cost[i][j]<<" ";
        }
    }
    dp[n] = 0;
    for (i = n-1; i >= 0; i--){
        m = INT_MAX, k = n;
        for (j = i + 1; j <= n; j++){
            if (cost[i][j - 1] == -1)
                continue;
            if (dp[j] + cost[i][j - 1] < m)
                {m = dp[j] + cost[i][j - 1] ;
                k = j;
                }
        }
        dp[i] = m;
        p[i] = k;
    }
    cout << "\nprinting costs \n";
    for (i = 0; i< n; i++)
        cout << dp[i] <<" " ; 
    cout << "\n printing words in each line \n";
    cout << p[0] << " ";
    for (i = p[0]; i< n;){
        cout << p[i] - i<<" " ; 
        i = p[i];
    }
    return  0;
}
