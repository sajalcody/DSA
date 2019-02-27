#include <iostream>
#include <vector>
using namespace std;

void printGraph(vector <int> g[5]){
    for(int i = 0; i < 5; i++){
        cout << i << "->";
        for(int adj:g[i])
            cout <<adj <<"->";
        cout << endl;
    }
}
void adjList(){ // => O(V+E)
    int vertices=5,a,b,e;
    vector <int> g[5];
    cout << "enter edges for graph with 5 vertices\n";
    cin >> e;
    while(e--){
        cin >> a >> b;
        g[a].push_back(b);
    }
    printGraph(g);

    // Transposing a Adj List

    vector <int> gT[5];
    for(int i=0; i < vertices; i++){
        for(int adj:g[i])
            gT[adj].push_back(i);
    }

    cout << "Transposed Graph\n";
    printGraph(gT);
}

int main(){
    adjList();
    // adjMat(); [TODO] // O(V^2)
}


/*Sample input

6
0 1
1 2
2 3
0 3
3 4
4 1
*/