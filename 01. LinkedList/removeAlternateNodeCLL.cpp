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


/* REMOVE ALTERNATE NODES FROM CLL
-We've to take care that it's a CLL so we don't wrap around while removing.
-For non-empty CLL, we'll never encounter NULL, so can't use it for breaking while.
-We don't need to return head as head isn't modified. If alternate starts from first node then we need to.
-> Brute Force Approach: call deleteNode for every node to be deleted T:O(n²), S:O(1)
-> implement deleteNode inside the calling function itself. T:O(n), S:O(1)
*/

void removeAlternatesBF(node *head){
  if(!head || head->next==head)
    return;
  node *currentNode = head;
  int targetNode;
  do{
    targetNode =currentNode -> next -> data;
    currentNode = currentNode -> next -> next;
    deleteNode(&head, targetNode);
  } while (currentNode != head && currentNode -> next != head); // first condition for even nodes and 2nd for odd
}

void removeAlternates(node *head){
  if(!head || head->next==head)
    return ;
  node *currentNode = head, *targetNode;
  do{
    targetNode = currentNode -> next;
    currentNode -> next = targetNode -> next;
    currentNode= currentNode -> next;
    delete targetNode;
  } while (currentNode != head && currentNode -> next != head); // first condition for even nodes and 2nd for odd
}

int main(){
  node *head = NULL; // initialise Empty List
  printList(head);
  insertEnd(&head, 1); // Insertion in Beginning
  insertEnd(&head, 2);
  insertEnd(&head, 3);
  insertEnd(&head, 4);
  insertEnd(&head, 5);
  insertEnd(&head, 6);
  insertEnd(&head, 7);
  insertEnd(&head, 8);
  insertEnd(&head, 9);
  insertEnd(&head, 10);
  // insertEnd(&head, 11);
  printList(head);
  removeAlternatesBF(head);
  printList(head);
  removeAlternates(head);
  printList(head);

  return 0;
}