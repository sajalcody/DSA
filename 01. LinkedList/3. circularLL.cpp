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

// Traversal => T:O(n), S:O(1)
void printList(node *head){
  if(!head) //Need to handle empty list
    {cout <<"Empty list\n"; return;}
  node *tempHead = head;
  do{
    cout << head -> data << " ";
    head = head -> next;
  } while(head!=tempHead);
  cout << endl;
}

/* INSERTION
-> in beginning => T:O(n), S:O(1)
=> Case of empty list is individually handled
-> in end => T:O(n), S:O(1)
=> Case of empty list is individually handled
*/

void insertBegin(node **head, int data){
  node *newNode = new node(data);
  if (! *head) // Empty List
    newNode -> next = newNode; // newNode points to itself
  else{
    newNode -> next = *head; // newNode point to old head;
    node *tempHead = *head;
    while(tempHead -> next != *head) // Reach the lastnode
      tempHead = tempHead -> next;
    tempHead -> next = newNode; // last node points to new node
  }
  *head=newNode; // Modifying head
}

void insertEnd(node **head, int data){
  node *newNode = new node(data);
  if (*head){
    node *tempHead = *head;
    while(tempHead -> next != *head) // Reach the lastnode
      tempHead = tempHead -> next;
    tempHead -> next = newNode; // last node points to new node
  }
  else // Empty List
    *head = newNode;
  newNode -> next = *head; // Modifying next of newly added last node
}

/* DELETION
-> in beginning => T:O(n), S:O(1)
=> Case of empty list is individually handled
-> in end => T:O(n), S:O(1)
=> Case of empty list is individually handled
-> Deleting a given node data
*/

void deleteBegin(node **head){
  if (! *head || (*head) -> next == *head) // Empty List || single-element list
    *head = NULL;
  else{
    node *tempHead = *head;
    while(tempHead -> next != *head) // Reach the lastnode
      tempHead = tempHead -> next;
    tempHead -> next = (*head) -> next; // lastnode points to next of head
    tempHead=*head;
    *head = (*head) -> next; // Modifying head
    delete tempHead;
  }
}

void deleteEnd(node **head){
  if (! *head || (*head) -> next == *head) // Empty List || single-element list
    *head = NULL;
  else{
    node *tempHead = *head, *freeNode;
    while(tempHead -> next -> next != *head) // Reach the second lastnode
      tempHead = tempHead -> next;
    freeNode = tempHead -> next;
    tempHead -> next = *head; // second lastnode points to next of head
    delete freeNode;
  }
}

void deleteNode(node **head, int targetNode){
  if(! *head) // Empty List
    return;
  node *nex=*head, *prev=*head;
  while(nex -> data != targetNode && nex -> next != *head){
    prev=nex;
    nex=nex -> next;
  }
  if(nex -> data != targetNode) // Node not found
    {cout << "Node not found\n"; return;}
  cout << "Node to be deleted is " << targetNode << " and nex is " << nex -> data << endl;
  if(nex -> next == nex) // Single-element list
    *head=NULL;
  else if(nex == *head){
    /* Target node is First node then 
        prev is also pointing to first node so traverse till last node*/
    while(prev -> next != nex)
      prev = prev -> next;
    *head = nex -> next;
  }
  prev -> next = nex -> next;
  delete nex;
}

int main(){
  node *head = NULL; // initialise Empty List
  printList(head);
  insertBegin(&head, 2); // Insertion in Beginning
  printList(head);
  insertEnd(&head, 3); // Insertion in end
  printList(head);
  insertBegin(&head, 1); // Insertion in Beginning
  printList(head);
  insertEnd(&head, 4); // Insertion in end
  printList(head);
  insertEnd(&head, 5); // Insertion in end
  printList(head);
  insertEnd(&head, 6); // Insertion in end
  printList(head);
  insertBegin(&head, 0); // Insertion in beginning
  printList(head);
  deleteBegin(&head); // Deletion from beginning
  printList(head);
  deleteNode(&head, -1); // Deleting node which does not exist
  printList(head);
  deleteNode(&head, 2); // Deleting node which exist in middle
  printList(head);
  deleteNode(&head, 1); // Deleting node which exist in front
  printList(head);
  deleteNode(&head, 6); // Deleting node which exist in end
  printList(head);
  deleteBegin(&head); // Deletion from beginning
  printList(head);
  deleteEnd(&head); // Deletion from end
  printList(head);
  deleteNode(&head, 4); // Deleting the only node
  printList(head);
  return 0;
}