// Graph Representation: Adjacency List

#include <iostream>
#include <vector>
#include <string.h> //memset
using namespace std;

//Directed Graph Representation
void insertEdgeDG (vector<int> graph[], int u, int v){
  graph[u].push_back(v);
}

// Using STL vector as linked list
void insertEdge (vector <int> graph[], int u, int v){
  graph[u].push_back(v);
  graph[v].push_back(u);
}


//Utility methods
void printGraph(vector <int> graph[], int vertices){
  for(int i = 0; i < vertices; i++){
    cout << i;
    for(int x : graph[i])
    cout << "-> " << x ;
    cout << "\n";
  }
}

// Using struct, Without STL

// Data structure to store Adjacency list nodes
struct listNode{
  int vertex;
  listNode *next;
};

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

int mainDef(){
    
    /* for STL representation 
    int t, v, e, a, b;
    cin >> t;
    while(t--){
      cin >> v >> e;
      vector <int> g[v];
      while(e--){
        cin >> a >> b;
        insertEdge(g,a,b);
      }
      printGraph(g,v);
      }
    */

   /* for Adjacency list without STL
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2); 
    g.addEdge(2,3); 
    g.addEdge(3,4); 
    g.addEdge(4,2); 
    g.addEdge(3,1); 
    g.showGraph();
    */

   // Adjacency Matrix
   int v,e, a, b;
   cin >> v;
   int g[v][v];
   memset(g, -1, sizeof(g)); // int g[v][v]={0};
   while(e--){
     cin >> a >> b;
     g[a][b] = g[b][a] = 1;
   }
    return 0;
}