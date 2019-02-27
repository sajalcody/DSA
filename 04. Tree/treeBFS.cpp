#include <iostream>
#include <queue> // queue STL
using namespace std;

struct node {
	int data;
	node *left, *right;
	node (int x){
		data = x;
		left = right = NULL;
	}
};

//BFS without differentiating in each level
void bfs(node *root){ // => T:O(n), S:O(n)
	if(!root)
		return;
	queue <node*> q;
	q.push(root);				// O(1)
	while(!q.empty()){			// O(1)
		node *temp=q.front();	// O(1)
		q.pop();				// O(1)
		cout << temp -> data << " ";
		if(temp -> left)
			q.push(temp -> left);
		if(temp -> right)
			q.push(temp -> right);
	}
}

// BFS for each level separate
void levelorder(node *root){ // => T:O(n), S:O(n)
	if(!root)
		return;
	queue <node*> q;
	q.push(root);				// O(1)
	q.push(nullptr);			// or NULL
	while(q.size() > 1){		// O(1)
		node *temp=q.front();	// O(1)
		q.pop();				// O(1)
		if(temp == nullptr){	// or !temp
				cout << "\n";
				q.push(nullptr);
		}
		else{
		cout << temp -> data << " ";
		if(temp -> left)
			q.push(temp -> left);
		if(temp -> right)
			q.push(temp -> right);
	}
	}
}
int main() {
	node *root = new node(1);
	root -> left = new node(2);
	root -> right = new node(3);
	root -> left -> left = new node(4);
	bfs(root);
	cout <<"\n";
	levelorder(root) ;
	return 0;
}