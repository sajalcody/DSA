#include<bits/stdc++.h>
using namespace std;

bool dfs(vector <int> adj[], int s, int e,int v){
    if
}

int heist(vector <int> s, int lock, int unlock){
    int v = s.size();
    map<int, int> m;
    for(int i =0;i<v;i++)
        m[s[i]]=i;
    vector <int> adj[v];
    for(int i = 0; i < v; i++){
        int p = s[i];
        for(int j = 0; j < 3; j++){
            int newp = p & pow(10,j);
            if(m.find(newp) != m.end()){
                adj[i].push_back(m[newp]);
                adj[m[newp]].push_back(i);
            }
        }
    }
    int startV = m[lock], endV = m[unlock];
    bfs(adj, startV, endV, V);
}