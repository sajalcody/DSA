#include <iostream>
#include <queue> // priority_queue
#include <vector> // vector
#include <functional> // std::greater
using namespace std;

/* NOTES
-> By default, pQ are maxHeap
-> top() of empty pQ gives SEGMENTATION FAULT
*/
int main(){
    int initArr[] = {10, 20, 15, 5};

    // MAXHEAP 
    priority_queue <int> p; // Empty maxHeap
    priority_queue <int> q(initArr, initArr+4); // maxHeap with 4 elements with 20(largest) at top;

    cout << "Max ele " << q.top() << "\n"; // => O(1); p.top() gives SEGMENTATION FAULT
    q.pop(); // => O(lg n)
    cout << "Max ele again " << q.top() << "\n";
    cout << "is empty? " << p.empty() << "\n"; // => O(1)
    cout << "Size: " << q.size() << "\n"; // => O(1)

    q.push(30); // => if (no reallocation) then O(lg n) else O(n)
    cout << "Max ele after push " << q.top() << "\n";

    //MINHEAP
    priority_queue <int, vector<int>, greater<int> > r; // Empty minHeap; Constructor(type, containerType, comparison)
    priority_queue <int, vector<int>, greater<int> > s(initArr, initArr+4); // minHeap with 4 elements with 5(smallest) at top

    cout << "Min ele " << s.top() << "\n"; // => O(1)
    s.pop(); // => O(lg n)
    cout << "Min ele again " << s.top() << "\n";
    cout << "is empty? " << r.empty() << "\n"; // => O(1)
    s.push(3); // => if (no reallocation) then O(lg n) else O(n)
    cout << "Mix ele after push " << s.top() << "\n";
}