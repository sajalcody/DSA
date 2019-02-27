#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack <int> a, mins;
    MinStack() {
        
        
    }
    
    void push(int x) {
        a.push(x);
        if(mins.empty())
        mins.push(x);
        else if(mins.top() > x)
            mins.push(x);
        else mins.push(mins.top());
    }
    
    void pop() {
        a.pop();
        mins.pop();
        
    }
    
    int top() {
        return a.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

int main() {
	MinStack s;
  cout << "stack init";
	s.push(2);
	cout << s.getMin();
	s.push(1);
	cout << s.getMin();
	s.push(3);
	cout << s.getMin();
	// your code goes here
	return 0;
}