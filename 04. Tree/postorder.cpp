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
void postorder(node*root){
	if(!root)
	return;
	postorder(root -> left);
	postorder(root -> right);
	cout << root -> data <<" ";
}

// ITERATIVE APPROACH 1

/* 
Postorder can be seen as reverse of preorder with the change of visiting root->right->left
So, follow prerder code and push elements in stack to later pop them in reverse order.
To get right child first, push right child after left child.
1. Push root to first stack.
2. Loop while first stack is not empty
   2.1 Pop a node from first stack and push it to second stack
   2.2 Push left and right children of the popped node to first stack
3. Print contents of second stack
*/

void postorder2Stacks(node *root){ // => T:O(n) , S:O(2n) USE 2 STACKS
    stack<node*> s;
    stack<int> printSt;
    node * temp;
    if(!root)
        return;
    s.push(root);
    while(!s.empty()){
        temp = s.top(); s.pop();
        printSt.push(temp->data);
        if (temp -> left) s.push(temp -> left);
        if(temp ->right) s.push(temp -> right);
    }
    while(!printSt.empty()){
        cout << printSt.top() <<" ";
        printSt.pop();
    }
}

int main() {
	
	node *root = new node(1);
	root -> left = new node(2);
	root -> right = new node(3);
	root -> left -> left = new node(4);
	postorder(root) ;
	cout << "\n" ;
	postorder2Stacks(root);
	return 0;
}