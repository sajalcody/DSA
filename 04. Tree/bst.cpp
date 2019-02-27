#include <iostream>
#include <queue>
using namespace std;

struct node{
    int data;
    node *left, *right;
};

node *newNode(int val){
    node *n = new node;
    n -> data = val;
    n -> left = n -> right = NULL;
    return n;
}

void bfs(node *root){
    queue <node*> q;
    q.push(root);
    node *temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout << temp -> data << " ";
        if(temp -> left)
            q.push(temp -> left);
        if (temp -> right)
            q.push(temp -> right);
    }
}

void inorder(node *root){
    if(root){
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}
node* insertBST(node *root, int val){
    if(!root)
        return newNode(val);
    if(val < root->data)
        root -> left = insertBST(root -> left, val);
    else // if dont want to insert repeated elements -> if(val > root->data)
        root -> right = insertBST(root -> right, val);
    return root;
}

node *searchBST(node *root, int val){
    if(!)
}
int main(){
    node *root = NULL;
    root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 70);
    insertBST(root, 60);
    insertBST(root, 80);
    insertBST(root, 50);
    cout << "BFS ";
    bfs(root); cout << endl;
    cout << "inorder ";
    inorder(root); cout << endl;
    return 0;
}