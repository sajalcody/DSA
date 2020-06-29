#include <bits/stdc++.h>
using namespace std;

int solve(int A, vector<int> &B, vector<vector<int> > &C) {
    if (A <= 1)
        return 0;
    int n = B.size(), px, py, pxi, pyi;
    cout << "a: " << A<< "n: " << n <<endl;
    int ans = 0;
    for (int i = n - 2*A; i< n; i+=2){
        for (int j = 0; j < n/2; j++){
            if (C[j][0] == B[i] || C[j][1] == B[i])
                px = C[j][0] == B[i] ? C[j][1] : C[j][0];
            else if (C[j][0] == B[i+1] || C[j][1] == B[i+1])
                py = C[j][0] == B[i+1] ? C[j][1] : C[j][0];
        }
        if (px != B[i+1]){
            cout << i+2 << ": ";
            for(int j = i+2; j < n; j++){
                cout << B[j] << " ";
                if (B[j] == px)
                    pxi = j;
                else if (B[j] == py)
                    pyi = j;
            }
            cout << "\n" << px << " " << pxi << " " << py << " " << pyi << endl;
            B[pxi] = B[i+1];
            B[i+1] = px;
            int ansx = solve(A-1, B, C);
            cout << "ansx: " << ansx << endl;
            B[i+1] = B[pxi];
            B[pxi] = px;
            B[pyi] = B[i];
            B[i] = py;
            int ansy = solve(A-1, B, C);
            cout << "ansy: " << ansy << endl;
            // if (ansx < ansy){
                B[i] = B[pyi];
                B[pyi] = py;
                // B[pxi] = B[i+1];
                // B[i+1] = px;
            // }
            cout << "finalArray for " << i << ": ";
            for (int x : B)
                cout << x << " ";
            cout << endl;
            ans = ans + 1 + min(ansx, ansy);
        }
    }
    return ans;
}

int main(){
    int a;
    cin >> a;
    vector <int> b(2*a);
    vector <vector <int> > c(a, vector <int> (2));
    for(int i = 0; i < 2*a;i++)
        cin >> b[i];
    for (int i = 0; i < a; i++)
        cin >> c[i][0] >> c[i][1];
    cout << "ans: " << solve (a, b, c) << endl;
}

/*
Sample input
1
2 1 
1 2

3
3 5 6 4 1 2
1 3
2 6
4 5

5
10 1 7 4 6 2 3 5 8 9
6 7
3 9
2 5
1 4
8 10
*/