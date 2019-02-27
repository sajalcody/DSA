#include <iostream>
#include <string> // memset
using namespace std;

#define Capacity 100

void root(char tree[], char r){
    // if(tree[0] == '\0')
    //     cout << "Root exists\n";
    // else 
        tree[0] = r;
}

void setLeft(char tree[], int parent, char val){
    if(tree[parent] =='\0')
        cout << "Parent does not exists\n";
    else if(parent * 2 > Capacity)
        cout << "No space\n";
    else tree[parent * 2 + 1] = val;
}

void setRight(char tree[], int parent, char val){
    if(tree[parent] =='\0')
        cout << "Parent does not exists\n";
    else if(parent * 2 + 1 > Capacity)
        cout << "No space\n";
    else tree[parent * 2 + 2] = val;
}

void printTreeBFS(char tree[]){ 
    for(int i = 0; i < 20; i++)
        if (tree[i] == '\0')
            cout << "- ";
        else
            cout << tree[i] << " ";
}
int main(){
    char tree[Capacity];
    memset (tree, '\0', sizeof(tree));
    root (tree, 'A');
    setLeft(tree, 0, 'B');
    setRight(tree, 0, 'C');
    setLeft(tree, 1, 'D');
    setRight(tree, 2, 'E');
    printTreeBFS(tree);
}