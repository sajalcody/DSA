#include <iostream>
#include <vector>
using namespace std;

#define m 1000

int minDistance(vector <int>  dist, vector <bool>  sptSet, int V) 
{ 
	int min = INT_MAX, min_index; 
	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 
	return min_index; 
} 

void dijkstra(vector <vector <int> > graph, int V, int src, int t, int a, int b) 
{ 
	vector <int> dist(V, INT_MAX);
    vector <int> flag(V, 0);
    vector <bool> sptSet(V, false);
	dist[src] = 0; 
	for (int count = 0; count <= t; count++) { 
		int u = minDistance(dist, sptSet, V); 
		sptSet[u] = true;
		for (int v = 0; v < V; v++){
			if (!flag[u] && graph[u][v] <= a){
                if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v]; 
            }
            else if (graph[u][v] >= b){
                flag[u] = 1;
                if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v]; 
            }
        }
	} 
    cout << dist[t];
} 

int main() 
{ 
	int v, e, a, b, x, y, w, s, t;
    cin >> v >> e;
	vector <vector <int> > g(m, vector<int> (m, 0));
    for (int i = 0; i < e; i++){
        cin >> x >> y >> w;
        x--; y--;
        g[x][y] = g[y][x] = w;
    }
    cin >>s>>t>>a>>b;
	dijkstra(g, v, s-1,t-1,a,b); 

	return 0; 
} 
