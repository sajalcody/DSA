#include <iostream>
using namespace std;

struct node{
  int data;
  node *next;

  node (int val){
    data = val;
    next = NULL;
  }
};

// Traversal => O(n)
void printList(node *head){
  while(head){
    cout << head -> data << " ";
    head = head -> next;
  }
  cout << endl;
}

/* Insertion
Take a double pointer to head as has to modify head; while calling i..(&head,..)
=>Edge case of empty list is being handled
=>[TODO] handle case if index does not invalid 
-> At Beginning => O(1) (Need to handle this individually)
-> Intermediate => O(n)
-> At end => O(n)
*/
void insertNode(node **head, int index, int data){
  node *newnode = new node(data);
  if(index == 0){ //INSERTION IN BEGINNING
    newnode -> next = *head;
    *head = newnode;
  }
  else{ // Insertion in middle and end
    node *nex = *head, *pre; // pre denotes PREVIOUS NODE OF NEWNODE, nex denotes NEXT NODE
    int k=0;
    while(nex && k<index){
      pre = nex;
      nex = nex -> next;
      k++;
    }
    pre -> next = newnode;
    newnode -> next = nex;
  }
}

/* Deletion
Take a double pointer to head as has to modify head; while calling i..(&head,..)
=>Edge case of empty list is being handled
=>[TODO] handle case if index does not invalid
-> At Beginning => O(1) (Need to handle this individually)
-> Intermediate => O(n)
-> At end => O(n)
*/
void deleteNode(node **head, int index){
  if(! *head) // For empty list
    return;
  if(index == 0){ // DELETION FROM Beginning
    node *temp = *head;
    *head = (*head) -> next;
    delete temp;
  }
  else{
    node *pre, *nex = *head;
    int k = 0;
    while (nex && k < index){
      pre=nex;
      nex=nex->next;
      k++;
    }
    pre -> next = nex -> next;
    delete nex;
  }
}

int main(){

  node *head = new node(1);
  head -> next = new node(2);
  head -> next -> next = new node(3);
  // node *head = NULL; // for edge case Empty List
  printList(head);
  insertNode(&head, 0, -1); // Insertion in Beginning
  printList(head);
  insertNode(&head, 4, 4); // Insertion in end
  printList(head);
  insertNode(&head, 0, -2); // Insertion in Beginning
  printList(head);
  insertNode(&head, 2, -0); // Insertion in Middle
  printList(head);
  deleteNode(&head, 0); // Deletion from beginning
  printList(head);
  deleteNode(&head, 3); // Deletion from middle
  printList(head);
  deleteNode(&head, 4); // Deletion from end
  printList(head);
  return 0;
}