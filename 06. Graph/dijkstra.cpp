#include <bits/stdc++.h>
using namespace std;

//////// DIJKSTRA ALGO ///////////
/*
-> Single Source Shortest Path Algo
-> weighted, directed graph
-> Greedy Algorithm, Non-negatuive edges, graph need not be connected
-> T: O(V^2 + E)
V^2 => There are V iterations and for each iteration, we go through all vertices to find unmarked, smallest vertex.
E => In total V^2 iterations, we relax an edge once.
*/

void dijkstra(int s, vector <vector <pair <int, int> > > adj, vector <int> &p, vector <int> &d){
    int v = adj.size();
    vector <int> marked(v, false);
    d.assign(v,INT_MAX);
    d[s] = 0;
    p[s] = -1;
    for (int i = 0; i < v; i++) {
        int j = -1;
        for (int k = 0; k < v; k++)
            if (!marked[k] && (j == -1 || d[k] < d[j]))
                j = k;
        marked[j] = true;
        if (d[j] == INT_MAX)
            break;
        for (auto pt: adj[j]){
            int to = pt.first;
            int wt = pt.second;
            if (d[to] > d[j] + wt){
                d[to] = d[j] + wt;
                p[to] = j;
            }
        }
    }
    for (int i = 0; i < v; i++){
        cout << s <<"->"<<i<<" "<<d[i] << " :: " << p[i] << endl;
    }
}

void restor_path(int s, int a, vector <int> p){
    vector <int> path;
    path.push_back(a);
    cout << a << ": ";
    while (a != s){
        path.push_back(p[a]);
        a = p[a];
    }
    reverse (path.begin(), path.end());
    for (int x : path)
        cout << x <<" -> ";
    cout << endl;
}

void dijkstraPQ(int s, vector <vector <pair <int,int> > > adj, vector <int> &d, vector <int> &p){
    int n = adj.size();
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater< pair<int, int> > > pq; // Min Heap
    d.assign(n, INT_MAX);
    d[s] = 0; p[s] = -1;
    pq.push(make_pair(0, s));
    while (!pq.empty()){
        pair <int, int> pr = pq.top(); pq.pop(); // EXTRACT_MIN
        if (pr.first == INT_MAX)
            break;
        for (auto pt : adj[pr.second]){
            int to = pt.first;
            int wt = pt.second;
            if(d[to] > d[pr.second] + wt){
                d[to] = d[pr.second] + wt;
                pq.push(make_pair(d[to], to)); // 
                p[to] = pr.second;
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << s <<"->"<<i<<" "<<d[i] << " :: " << p[i] << endl;
    }
}

int main(){
    int v, e;
    cin >> v >> e;
    vector <int> d(v), p(v);
    vector <vector <pair <int, int> > > adj(v);
    int a, b, w;
    while (e--){
        cin >> a >> b >> w;
        adj[a].emplace_back(b,w);
    }
    int s;
    cin >> s;
    dijkstra(s, adj, p, d);
    cout <<"\n using priority_queue\n";
    dijkstraPQ(s, adj, p, d);
    int q;
    cin >> q;
    while (q--){
        cin >> a;
        restor_path(s, a, p);
    }
    return 0;
}

/*
Sample Input 1
5 9
0 1 10
0 2 3
1 2 1
2 1 4
1 3 2
2 3 8
2 4 2
3 4 7
4 3 9
0

Sample Input 2 (Undirected graph given as direceted graph)
9 28
0 1 4
1 0 4
0 7 8
7 0 8
1 2 8
2 1 8
1 7 11
7 1 11
2 3 7
3 2 7
2 8 2
8 2 2
2 5 4
5 2 4
3 4 9
4 3 9
3 5 14
5 3 14
4 5 10
5 4 10
5 6 2
6 5 2
6 7 1
7 6 1
6 8 6
8 6 6
7 8 7
8 7 7
0
*/
