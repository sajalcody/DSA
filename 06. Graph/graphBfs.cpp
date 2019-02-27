#include<iostream>
#include <vector> // vector
#include <queue> // queue
#include <string> //memset
using namespace std;

void printGraphAdj(vector <int> graph[], int vertices){
  for(int i = 0; i < vertices; i++){
    cout << i;
    for(int x : graph[i])
        cout << "-> " << x ;
    cout << "\n";
  }
}

void printGraphMat(int g[][8], int v){
  cout << "\n Matrix Representation: \n";
  cout << "   ";
  for(int i = 0; i < v; i++)
    cout << i << "  ";
  cout << endl;
  for(int i = 0; i < v; i++){
    cout << i << "  ";
    for (int j = 0; j < v; j++)
      cout << g[i][j] << "  ";
    cout << endl;
  }
}

/* Graph BFS ADJACENCY LIST USING STL
calling func: bfsTraversalSTL
util func: bfsSTL
T:O(|V|+|E|) -> For Adjacency List(bfsSTL)
S:O(|V|)
*/

void bfsSTL(int source, bool visited[], vector<int> g[]){
    queue <int> q;
    q.push(source);
    visited[source]= true;
    while(!q.empty()){
        int currentV = q.front();q.pop();
        cout << currentV << " -> ";
        for(int adjacentV : g[currentV]){
            if(!visited[adjacentV])
                q.push(adjacentV);
                visited[adjacentV]=true;
        }
    }
}

// The following func is required to visit all nodes. 
void bfsTraversalSTL(int v, vector <int> g[]){
    bool visited[v];
    memset(visited, false, sizeof(visited));
    for(int vertex = 0; vertex < v; ++vertex){
        if(!visited[vertex]){
            // cout << "\nNext Component\n";
            bfsSTL(vertex, visited, g);
        }
    }

}

void callBfsAdjSTL(){
  int v = 8, e, a, b;
  vector <int> adj[v]; // Array adj of |V| lists
  cout << "enter edges' count for di-graph(STL) with 8 vertices ";
  cin >> e;
  while(e--){
    cin >> a >> b;
    adj[a].push_back(b);
    // adj[b].push_back(a); // For un-directed graph
  }
  printGraphAdj(adj,v);
  cout << "\n BFS Traversal of Adj list using STL \n";
  bfsTraversalSTL(v, adj);
}

/* Graph BFS ADJACENCY MATRIX
calling func: bfsTraversalMat
util func: bfs
T:O(V^2) -> For Adjacency Matrix
S:O(|V|) -> For visited array
*/

void bfs(int source, int v, bool visited[], int g[][8]){
    queue <int> q;
    q.push(source);
    visited[source]= true;
    while(!q.empty()){
        int currentV = q.front();q.pop();
        cout << currentV << " -> ";
        for(int adjacentV=0; adjacentV < v; adjacentV++){
            if(g[currentV][adjacentV] && !visited[adjacentV]){
                q.push(adjacentV);
                visited[adjacentV]=true;
            }
        }
    }
}

void bfsTraversalMat(int v, int g[][8]){ 
    bool visited[v];
    memset(visited, false, sizeof(visited));
    for(int vertex = 0; vertex < v; ++vertex){
        if(!visited[vertex])
            bfs(vertex, v, visited, g);
    }
}
void callBfsMat(){
  int v = 8, e, a, b;
  int g[v][8]; // Can't declare g[v][v] as it gives error when passed to function
  memset(g, 0, sizeof(g));
  cout << "enter edges' count for graph(matrix) with 8 vertices ";
  cin >> e;
  while(e--){
    cin >> a >> b;
    g[a][b] = 1;
    // g[b][a] = 1; // For un-directed graph
   }
  printGraphMat(g, v);
  cout << "\n BFS Traversal of Adj matrix \n";
  bfsTraversalMat(v, g);
}

//[TODO]
/* Graph BFS ADJACENCY MATRIX USING STRUCT
calling func: bfsTraversalMat
util func: bfs
T:O() -> For Adjacency Matrix
S:O(|V|) -> For visited array

void bfs(int v, bool visited[], listNode **g){
}
*/

int main(){
    callBfsAdjSTL();
    callBfsMat();
    return 0;
}

/* SAMPLE TESTCASE
8
0 1
1 7
1 2
2 3
2 4
7 4
4 6
5 4

7
0 1
1 6
0 7
7 2
5 4
5 3
4 3

for v=5
7
0 1
0 4
1 2 
2 3 
3 4 
4 2 
3 1
*/