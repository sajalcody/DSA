#include <iostream>
using namespace std;

/* Q. https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
What is nth node does not exist? => Can return -1
*/

struct node{
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void printList(node *head){
  while(head){
    cout << head -> data << " ";
    head = head -> next;
  }
  cout << endl;
}

/* Approach 1: TWO SCAN APPROACH
Find length in first scan
return length-n+1 node from beginning
*/
int nthFromEnd(node *head, int n){
    int length = 0;
    node *tempHead = head;
    while(tempHead){
        tempHead = tempHead->next;
        length++;
    }
    int target = length-n; // Theoretically it should be length-n+1 then have to modify while condn to (target-- > 1)
    while(target--)
        head = head->next;
    return head ->data;
}

/* Approach 2: SINGLE SCAN APPROACH, USING 2 POINTERS
Move forward pointers n steps, while prev still points to head
start moving both till forward reaches end.
*/
int nthFromEnd_(node *head, int n){
    node *forward = head, *prev=head;
    while(forward){
        if(n) // Once n hits 0 it won't come here
            n--;
        else prev = prev -> next;
        forward = forward ->next;
    }
    return prev->data;
}

int main(){
    node *head = new node(1);
    // head->next=new node(3);
    // head->next->next=new node(2);
    // head->next->next->next=new node(4);
    // head->next->next->next->next=new node(-5);
    printList(head);
    // cout << "5 node from end " << nthFromEnd_(head, 5) << endl;
    // cout << "3 node from end " << nthFromEnd_(head, 3) << endl;
    cout << "1 node from end " << nthFromEnd_(head, 1) << endl;
}