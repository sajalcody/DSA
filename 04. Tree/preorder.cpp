#include <iostream>
#include <stack> 
using namespace std;

struct node {
	int data;
	node *left, *right;
    node (int x){
		data = x;
		left = right = NULL;
	}
};

// RECURSIVE APPROACH
void preorder(node*root){
	if(!root)
	return;
	cout << root -> data <<" ";
	preorder(root -> left);
	preorder(root -> right);
}

// Link: https://www.geeksforgeeks.org/iterative-preorder-traversal/
// ITERATIVE APPROACH 1: 
/* Conversion of recursive approach by using explicit stack. 
   In recursion also, first current node is printed, then its left child is called and then right.
   Here, in order to call left child first, we need to push it at last
   So, first push right child and left child
1) Create an empty stack nodeStack and push root node to stack.
2) Do following while nodeStack is not empty.
….a) Pop an item from stack and print it.
….b) Push right child of popped item to stack
….c) Push left child of popped item to stack */
void preorderi1 (node *root){ // => T: O(n), S:O(n)
	stack <node*> s;
	if(!root)
		return;
	s.push(root);
	while (!s.empty()){ 		//O(1)
		node *temp=s.top(); 	//O(1)
		s.pop();				//O(1)
		cout << temp -> data <<" ";
		if(temp -> right)
		s.push(temp -> right);	//O(1)
		if(temp -> left)
		s.push(temp -> left);	//O(1)
		
	}
}
// ITERATIVE APPROACH 2
/*  1. Process root 
	2. Store root and change root to its left
	3. After left subtree is done, change root to stack's top -> right
	4. pop

In step 2,
i. if we store the root, we don't need an if condition to check whether the root->right is null
     as it will be handled by 2nd while but we need to change root to top() -> right
ii. if we store root -> right, we need an if condition to check if root -> right is null
    then root will be changed to top
S: Only right child are being stored
But in worst case(right skewed tree),H=n; O(H) */
void preorderi2(node *root){ // => T: O(n), S: O(H)
	stack <node*> s;
	if(!root) // Edge Case
		return;
	while(1){
		while(root){
			cout << root -> data << " ";
			if(root -> right) // or replace if with s.push(root) and change line 76 to root = s.top() -> right;
				s.push(root -> right);	//O(1)
			root = root -> left;
		}
		if(s.empty())			//O(1)
			return;
		root = s.top();//O(1)
		s.pop();				//O(1)
	}
}
int main() {
	
	node *root = new node(1);
	root -> left = new node(2);
	root -> right = new node(3);
	root -> left -> left = new node(4);
	preorder(root) ;
	cout << "\n";
	preorderi1(root) ;
	cout << "\n" ;
	preorderi2(root);
	return 0;
}