#include <iostream>
#include <string.h> // memcpy
using namespace std;


//STACK IMPLEMENTATION USING DYNAMIC ARRAYS
class stack{
	int top;
	int *a;
  int capacity;
	public:

	stack () {
		top = -1;
    a = new int[1];
    capacity = 1;
	}
	bool push(int val); // O(1) AVERAGE; SPace Complexity: O(n) for n push operations
	void pop(); // O(1)
	int topElement(); // O(1)
	int size(); // O(1)
	bool isEmpty(); // O(1)
  bool isFullStack();// Indicates whether the stack is full or not.
  void doubleStack();
};

void stack::doubleStack(){
  cout << "Array being doubled\n";
  capacity *= 2;
  int *newArr = new int[capacity];
  memcpy (newArr, a, (capacity / 2) * sizeof(int) );
  // for(int i = 0; i < capacity / 2; i++)  //ALTERNATIVE FOR MEMCPY
  // newArr[i] = a[i];
  delete [] a;
  a = newArr;
}
bool stack::push(int val){
	if (isFullStack())
    doubleStack();
	a[++top] = val;
  cout << "Pushed " << val << "\n";
	return true;
}
void stack::pop(){
	if(top == -1){
		cout << "Stack Underflow";
		return;
	}
  cout << a[top] << " popped from stack\n";
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
	return top == -1;
}
bool stack::isFullStack(){
  return top == capacity - 1;
}

int main() {
	// your code goes here
	class stack s; 
    s.push(10); 
    s.push(20); 
    s.push(30); 
    cout << s.topElement() << " is at top\n";
    s.pop();
    cout << s.topElement() << " is at top\n";
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.push(16);
    s.push(17);
    s.push(18);
    s.push(19);
    s.push(20);
    s.push(21);
    s.push(22);
    s.push(23);
    s.push(24);
	return 0;
}