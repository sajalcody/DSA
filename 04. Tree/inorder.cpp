#include <iostream>
#include <stack> 
using namespace std;

struct node {
	int data;
	node *left, *right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};

// RECURSIVE APPROACH
void inorder(node*root){
	if(!root)
	return;
	inorder(root -> left);
	cout << root -> data <<" ";
	inorder(root -> right);
}

// ITERATIVE APPROACH 1

/* 
Similar like iterative approach in preoder, there we were printing then pushing, here we will push and then print outside inner while.
1) Create an empty stack S.
2) Initialize current node as root
3) Push the current node to S and set current = current->left until current is NULL
4) If current is NULL and stack is not empty then 
     a) Pop the top item from stack.
     b) Print the popped item, set current = popped_item->right 
     c) Go to step 3.
5) If current is NULL and stack is empty then we are done.*/

void inorderi1(node *root){ // => O(n)
	stack <node*> s;
	if(!root)
		return;
	while(1){
		while(root){
			s.push(root);
			root = root -> left;
		}
		if(s.empty())			//O(1)
			return;
		root = s.top();//O(1)
		cout << root -> data << " ";
		root = root -> right;
		s.pop();				//O(1)
	}
}
int main() {
	
	node *root = new node(1);
	root -> left = new node(2);
	root -> right = new node(3);
	root -> left -> left = new node(4);
	inorder(root) ;
	cout << "\n" ;
	inorderi1(root);
	return 0;
}