#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs(int s, vector<int> g[], vector <bool> &visited){
    visited[s] = true;
    cout << s << " -> ";
    for (int v : g[s]){
        if (!visited[v])
            dfs(v, g, visited);
    }
}
int main(){
    int e, v, a, b;
    cin >> v >> e;
    vector <int> g[v];
    for (int i = 0; i < e; i++){
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 0; i < v; i++){
        cout << i << ": ";
        vector <bool> visited(v, false);
        bool motherExist = true;
        dfs(i, g, visited);
        cout << "\n";
        for (bool b : visited)
            motherExist = motherExist && b;
        if (motherExist){
            cout << "mother vertex: " << i;
            break;
        }
    }
    // cout << "Mother does not exist";
}

/*
Sample Input 1
6
8
0 1 0 2
1 3 4 1
5 2 5 6
6 0 6 4
Ouput: 5
*/