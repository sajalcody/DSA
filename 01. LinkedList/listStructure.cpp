#include <iostream>
using namespace std;

/* NOTES
 Either use the contructor node or the following function
 node *newNode(int data){
	node *n = new node;
    if (!n){ // this case need to be handled inside main also where newNode is being called
        cout << "Memory allocation failed\n";
        return NULL;
    }
	n -> data = data;
	n -> next = NULL;
	return n;
}
USAGE: node *n = newNode (1);
*/

struct node {
	int data;
	node *next;
    // Constructor for node type

	node (int x){ // Parameterised Constructor: if only this is declared 'node *n = new node' gives ERROR
		data = x; // equiv to 'this -> data = x'
		next = NULL;
	}

    node (){
        data = 0;
        next = NULL;
    }
};

/* Declaration 1: No constructor and define function newNode */
struct node {
    int data;
    node *next;
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
    n -> next =  NULL;
    return n;
}
int main(){
    return 0;
}