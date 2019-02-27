#include <iostream>
#include <vector>
#include <string> //memset
#include <stack> //stack
#include <queue> // queue
using namespace std;

// [TODO]: William Fiset Approach
/* TOPOLOGICAL SORT
-> For Directed Acyclic Graph(DAG)
1. Topological Sorting Using DFS,Uses Stack O(|V| + |E|) [CLRS approach]
2. Topological Sorting Using indegree (Kahn's Algo),Uses Queue O(|V| + |E|) [Karumanchi approach]
3. Topological Sorting Using Departure time [TODO]
*/
void insertEdgeDG (vector <int> g[], int source, int destination){
    g[source].push_back(destination);
}

void printGraph (vector <int> g[], int v){
    for (int  i = 0; i < v; i++){
        cout << i << ": ";
        for(int vertex : g[i])
            cout << "-> " << vertex;
        cout << endl;
    }
}

// Topological Sorting Using DFS,Uses Stack O(|V| + |E|)
// can also use vector, but print reverse

void dfs(int currentV, vector <int> adj[], bool visited[], stack <int> &ordering){
    visited[currentV] =true;
    for(int adjV :adj[currentV]){
        if(!visited[adjV])
            dfs(adjV, adj, visited, ordering);
    }
    ordering.push(currentV);
}

void topoSortDfs(vector<int> g[], int v){
    bool visited[v];
    memset(visited, false,sizeof(visited));
    stack <int> ordering;
    for(int vertex=0; vertex < v; vertex++){
        if(!visited[vertex])
            dfs(vertex, g, visited, ordering);
    }
    while(!ordering.empty()){
        cout << ordering.top() << " -> ";
        ordering.pop();
    }

}

/* Kahn's Algorithm, T:O(|V|+|E|)
->Use in-degree
->Based on fact that:
--A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0.
*/

void getIndegree(vector <int> g[], int v, int indegree[]){ 
    for(int vertex=0; vertex < v; vertex++){
        for(int adjV : g[vertex])
            indegree[adjV]++;
    }
}

void topoSortIndegree(vector<int> g[], int v){
    int indegree[v], ordering[v], orderingIndex = 0;
    memset(indegree, 0, sizeof(indegree));
    getIndegree(g, v, indegree);
    queue <int> q;
    for(int vertex=0; vertex < v; vertex++){
        if(!indegree[vertex])
            q.push(vertex);
    }
    while(!q.empty()){
        int currentV = q.front();q.pop();
        ordering[orderingIndex++]=currentV;
        for(int adjV:g[currentV]){
            if(--indegree[adjV] == 0)
                q.push(adjV);
        }
    }
    for(int i = 0; i < v; i++)
        cout << ordering[i] << " -> ";
}

int main(){
    int v = 8;
    vector <int> g[v];
    insertEdgeDG(g, 1,2);
    insertEdgeDG(g, 1,7);
    insertEdgeDG(g, 0,1);
    insertEdgeDG(g, 2,3);
    insertEdgeDG(g, 2,4);
    insertEdgeDG(g, 7,4);
    insertEdgeDG(g, 4,6);
    insertEdgeDG(g, 5,4);
    printGraph(g,v);
    cout << "Topo Sort by DFS\n";
    topoSortDfs(g,v);
    cout << "\n Topo Sort by Kahn's algo(in-degree)\n";
    topoSortIndegree(g, v);

    return 0;
}

/* William Fiset Approach 1
Calling in main
    vector <int> ordering = topoSortWF(g,v);
    for(int x: ordering)
        cout << x << "-> ";
*/

void dfsWF(int at, vector <bool> &visited, vector<int> &visitedNodes, vector<int> g[]){ 
    visited[at]=true;
        for(int x:g[at]){
            if(!visited[x])
                dfsWF(x, visited, visitedNodes, g);
        }
    visitedNodes.push_back(at);
}


vector <int> topoSortWF(vector <int> g[], int v){
    vector<bool> visited(v,false); // int visited[v]={0}
    vector <int> ordering(v,0);
    int i = v - 1; //To track index for ordering array (we insert from last)

    for (int at = 0; at < v; at++){ // can start from any arbitary node
        if(!visited[at]){ 
            vector <int> visitedNodes;
            dfsWF(at, visited, visitedNodes, g);
            for (int nodeId : visitedNodes)
                ordering[i--]=nodeId;
        }
    }
    return ordering;
}