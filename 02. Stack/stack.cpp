#include <iostream>
using namespace std;

#define MAX 100

//STACK IMPLEMENTATION USING ARRAYS
class stack{
	int top;
	int *a;
	public:
	
	stack () {
		top = -1;
    a = new int[MAX];
	}
	bool push(int val); // O(1); SPace Complexity: O(n) for n push operations
	void pop(); // O(1)
	int topElement(); // O(1)
	int size(); // O(1)
	bool isEmpty(); // O(1)
  // int IsFullStack(): Indicates whether the stack is full or not.
};

bool stack::push(int val){
	if (top == MAX - 1){
		cout <<"Stack Overflow";
		return false;
	}
	a[++top] = val;
	return true;
}

void stack::pop(){
	if(top == -1){
		cout << "Stack Underflow";
		return;
	}
	top--;
}

int stack::topElement(){
	if(top == -1){
		cout << "Stack is Empty";
		return 0;
	}
	return a[top];
}

int stack::size(){
	return top + 1;
}

bool stack::isEmpty(){
	if(top == -1)
		return true;
	return false;
}

int main() {
	// your code goes here
	class stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.topElement() << " ";
    s.pop();
    cout << s.topElement() << " Popped from stack\n"; 
	return 0;
}