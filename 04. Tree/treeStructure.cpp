#include <iostream>

/* NOTES
 Either use the contructor node or the following function
 node *newNode(int data){
	node *n = new node;
    if (!n){ // this case need to be handled inside main also where newNode is being called
        cout << "Memory allocation failed\n";
        return NULL;
    }
	n -> data = data;
	n -> left = n -> right = NULL;
	return n;
}
USAGE: node *n = newNode (1);
*/

struct node {
	int data;
	node *left, *right;
    // Constructor for node type

	node (int x){ // Parameterised Constructor: if only this is declared 'node *n = new node' gives ERROR
		data = x; // equiv to 'this -> data = x'
		left = right = NULL;
	}

    node (){
        data = 0;
        left = right = NULL;
    }
};

/* Declaration 1: No constructor and define function newNode */
struct node {
    int data;
    node *left, *right;
};

node *newNode(int val){
    node *n = new node;

    /* Handling Memory allocation Error

    if (!n){ // this case need to be handled inside main also where newNode is being called
        cout << "Memory allocation failed\n";
        return NULL;
    }

    */

    n -> data = val;
    n -> left = n -> right = NULL;
    return n;
}