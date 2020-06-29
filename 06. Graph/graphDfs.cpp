#include<iostream>
#include <vector> // vector
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

/* Graph DFS ADJACENCY LIST USING STL
calling func: dfsTraversalSTL
util func: dfsSTL
T:O(|V|+|E|) -> For Adjacency List(dfsSTL)
S:O(|V|)
*/

// Function to start DFS from a given source
void dfsSTL(int source, bool visited[], vector<int> g[]){
    visited[source] = true;
    cout << source << " -> ";
    for(int x : g[source]){
        if(!visited[x])
            dfsSTL(x, visited, g);
    }
}

// Call DFS for every unvisited vertex
void dfsTraversalSTL(int v, vector <int> g[]){ 
    bool visited[v];
    memset(visited, false, sizeof(visited));
    for(int vertex = 0; vertex < v; ++vertex){
        if(!visited[vertex])
            dfsSTL(vertex, visited, g);
    }

}

void callDfsAdjSTL(){
  int v = 8, e, a, b;
  vector <int> adj[v]; // Array adj of |V| lists
  cout << "enter edges' count for di-graph(STL) with 8 vertices ";
  cin >> e;
  while(e--){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a); // For un-directed graph
  }
  printGraphAdj(adj,v);
  cout << "\n DFS Traversal of Adj list using STL \n";
  dfsTraversalSTL(v, adj);
}

/* Graph DFS ADJACENCY MATRIX
calling func: dfsTraversalMat
util func: dfs
T:O(V^2) -> For Adjacency Matrix
S:O(|V|) -> For visited array
*/

void dfs(int currentV, int v, bool visited[], int g[][8]){
    visited[currentV] = true;
    cout << currentV << " -> ";
    for(int endVertex=0; endVertex < v; endVertex++){
        if(g[currentV][endVertex] && !visited[endVertex])
            dfs(endVertex, v, visited, g);
    }
}

void dfsTraversalMat(int v, int g[][8]){ 
    bool visited[v];
    memset(visited, false, sizeof(visited));
    for(int vertex = 0; vertex < v; ++vertex){
        if(!visited[vertex])
            dfs(vertex, v, visited, g);
    }
}
void callDfsMat(){
  int v = 8, e, a, b;
  int g[v][8]; // Can't declare g[v][v] as it gives error when passed to function
  memset(g, 0, sizeof(g));
  cout << "enter edges' count for graph(matrix) with 8 vertices ";
  cin >> e;
  while(e--){
    cin >> a >> b;
    g[a][b] = 1;
    g[b][a] = 1; // For un-directed graph
   }
  printGraphMat(g, v);
  cout << "\n DFS Traversal of Adj matrix \n";
  dfsTraversalMat(v, g);
}

int main(){
    callDfsAdjSTL();
    callDfsMat();
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

//[TODO]
/* Graph DFS ADJACENCY MATRIX USING STRUCT
calling func: dfsTraversalMat
util func: dfs
T:O() -> For Adjacency Matrix
S:O(|V|) -> For visited array

void dfs(int v, bool visited[], listNode **g){
    visited[v] = true;
    cout << v << " -> ";
    listNode *head = g[v];
    while(head){
        if(!visited[head -> vertex]){
            visited[head -> vertex] = true;
            dfs(head -> vertex, visited, g);
        }
        head = head -> next;
    }
}
*/
