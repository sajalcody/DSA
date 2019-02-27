#include <iostream>
#include <vector> // vector
#include <string.h> //memset
using namespace std;

// [TODO] Overload function for printGraph
//Utility methods
void printGraphAdj(vector <int> graph[], int vertices){
  for(int i = 0; i < vertices; i++){
    cout << i;
    for(int x : graph[i])
    cout << "-> " << x ;
    cout << "\n";
  }
}

void printGraphMat(int g[][6], int v){
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

/*DIRECTED Graph Representation
-> Sum of lengths of all adjacency lists = |E|
*/

/* Adjacency List (Di-graph)
S: O(V+E)
T for calculating out-degree for each vertex: O(|V|+|E|)
T for calculating in-degree for each vertex:  O(|V|+|E|)
-> Does not give fast lookup for an edge
-> Suitable for sparse graphs
*/

////////////// DI-GRAPH ADJACENCY LIST USING STL ////////////////

void insertEdgeDG (vector<int> graph[], int u, int v){
  graph[u].push_back(v);
}

void diAdjSTL(){
  int v = 6, e, a, b;
  vector <int> adj[v]; // Array adj of |V| lists
  cout << "enter edges' count for di-graph(STL) with 6 vertices ";
  cin >> e;
  while(e--){
    cin >> a >> b;
    insertEdgeDG(adj,a,b);
  }
  printGraphAdj(adj,v);
}

/* Adjacency Matrix (Di-graph)
S: O(V^2)
-> Give fast lookup for an edge
-> G = Transpose(G) (only for undirected graph)
*/

void diMat(){
  int v = 6, e, a, b;
  int g[v][6];
  memset(g, 0, sizeof(g)); // int g[v][v]={0}; May give error
  cout << "enter edges' count for di-graph(matrix) with 6 vertices ";
  cin >> e;
  while(e--){
    cin >> a >> b;
    g[a][b] = 1;
   }
  printGraphMat(g, v);
}

/*UN-DIRECTED Graph Representation
-> Sum of lengths of all adjacency lists = 2*|E|
*/

////////////// GRAPH ADJACENCY LIST USING STL ////////////////

void insertEdge (vector <int> graph[], int u, int v){
  graph[u].push_back(v);
  graph[v].push_back(u);
}

void adjSTL(){
  int v = 6, e, a, b;
  vector <int> adj[v]; // Array adj of |V| lists
  cout << "enter edges' count for graph(STL) with 6 vertices ";
  cin >> e;
  while(e--){
    cin >> a >> b;
    insertEdge(adj,a,b);
  }
  printGraphAdj(adj,v);
}

////////////// GRAPH ADJACENCY LIST USING Struct ////////////////

// 1. Data structure to store Adjacency list nodes
struct listNode{
  int vertex;
  listNode *next;
};

// 2. Class Graph
class Graph{
  public:
  int v, e;
  listNode **adj; // Head pointers to linked list; // An array of pointers to Node to represent adjacency list NOTE: DOUBLE POINTER
  Graph(int V){
    v = V;
    adj = new listNode*[v];
    for(int i = 0; i < v; i++) //Initialise head to NULL of all vertices
      adj[i] = nullptr; 
    /* NOTE : new type vs new type()
    */
  }

  void addEdge(int U, int V){
    listNode *tempV = new listNode;
    tempV -> vertex = V;
    tempV -> next = adj[U];
    adj[U] = tempV;
    cout << "Added "<<V<<" to "<<U << endl;
    listNode *tempU = new listNode;
    tempU -> vertex = U;
    tempU-> next = adj[V];
    adj[V] = tempU;
    cout << "Added "<<U<<" to "<<V<<endl;
  }
  void showGraph(){
    for(int i = 0; i < v; i++){
      listNode *head = adj[i];
      cout << "Vertex " << i;
      while(head){
        cout << "-> " << head -> vertex;
        head = head -> next;
      }
      cout << endl;
    }
  }
};

// 3. Calling Function
void adjStruct(){
  int v = 6, e, a, b;
  Graph g(v);
  cout << "enter edges' count for graph(Struct) with 6 vertices ";
  cin >> e;
  while(e--){
    cin >> a >> b;
    g.addEdge(a,b);
  }
  /*
  g.addEdge(0,1);
  g.addEdge(0,4);
  g.addEdge(1,2); 
  g.addEdge(2,3); 
  g.addEdge(3,4); 
  g.addEdge(4,2); 
  g.addEdge(3,1); 
  */
  g.showGraph();
}

////////////// GRAPH ADJACENCY MATRIX ////////////////
void mat(){
  int v = 6, e, a, b;
  int g[v][6]; // Can't declare g[v][v] as it gives error when passed to function
  memset(g, 0, sizeof(g)); // int g[v][v]={0};
  cout << "enter edges' count for graph(matrix) with 6 vertices ";
  cin >> e;
  while(e--){
    cin >> a >> b;
    g[a][b] = g[b][a] = 1;
   }
  printGraphMat(g, v);
}

int main(){

  cout << "DIRECTED GRAPH \n";
  diAdjSTL();
  diMat();

  cout << "UN-DIRECTED GRAPH \n";
  adjSTL();
  adjStruct();
  mat();
    return 0;
}