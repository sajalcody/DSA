#include <iostream>
#include <limits.h>
using namespace std; // INT_MIN

/* PROPERTIES OF HEAP
Height of Heap(h): (lg n)
Min Nodes in Heap: 2^h
Max Nodes in Heap: 2^(h+1)-1
*/

class MinHeap {
    int *arr;
    int size;
    int capacity;
    public:
    // CONSTRUCTORS
    MinHeap(int capacity);
    MinHeap(int initArray[], int n, int capacity);

    // ACCESSORS
    void minHeapify(int index); // O(lg n)
    void buildMinHeap(); // O(n)

    int getMin(); // O(1)
    int extractMin(); // O(lg n)
    void insertKey(int key); // O(lg n)
    void deleteKey(int index); // O(lg n)
    void decreaseKey(int index, int newVal); // O(lg n)

    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i + 1; // 2<<i + 1
    }
    int right(int i){
        return 2*i + 2;
    }

    void printHeap(); //Not required

};

MinHeap::MinHeap(int c){
    capacity = c;
    arr = new int[capacity];
    size = 0;
}

MinHeap::MinHeap(int initArray[], int n, int c){
    capacity = c;
    arr = new int[capacity];
    size = n;
    for(int i = 0; i < n; i++)
        arr[i]=initArray[i];
    buildMinHeap();
}

void MinHeap::minHeapify(int i){ // => O(lg n)
    int smallest = i, l = left(i), r = right(i);
    if(l < size && arr[l] < arr[smallest])
        smallest = l;
    if(r < size && arr[r] < arr[smallest])
        smallest = r;
    if(smallest != i){
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
        minHeapify(smallest);
    }
}

/* ITERATIVE MINHEAPIFY
void MinHeap::minHeapify(int i){ // => O(lg n)
    while(i < size){
        int smallest = i, l = left(i), r = right(i);
        if(l < size && arr[l] < arr[smallest])
            smallest = l;
        if(r < size && arr[r] < arr[smallest])
            smallest = r;
        if(smallest != i){
            int temp = arr[smallest];
            arr[smallest] = arr[i];
            arr[i] = temp;
            i = smallest;
        }
        else
            return;
    }
}
*/

void MinHeap::buildMinHeap(){ // => O(n)
    for(int i=(size - 1)/2; i >= 0; i--)
        minHeapify(i);
}

int MinHeap::getMin(){ // => O(1)
    return arr[0];
}

int MinHeap::extractMin(){ // => O(lg n)
    if(size < 0)
        return INT_MIN;
    int min = arr[0];
    arr[0] = arr[size - 1];
    size--;
    minHeapify(0);
    return min;
}

void MinHeap::insertKey(int key){ // => O(lg n)
    if(size == capacity){
        cout << "Overflow\n";
        return;
    }
    arr[size] = key;
    int index = size++;
    while(index != 0 && arr[parent(index)] > arr[index]){
        int temp = arr[index];
        arr[index] = arr[parent(index)];
        arr[parent(index)] = temp;
        index = parent(index);
    }
}

void MinHeap::deleteKey(int index){ // => O(lg n)
    if (index >= size){
        cout << "Index does not exist\n";
        return;
    }
    arr[index]=arr[--size];
    minHeapify(index);
}

/*
decreaseKey of MinHeap is different from MaxHeap as 
here the new element which is decreased will climb up
and not drop downwards in the tree
*/
void MinHeap::decreaseKey(int index, int newVal){ // => O(lg n)
    if (index >= size){
        cout << "Index does not exist\n";
        return;
    }
    arr[index]=newVal;
    while(index != 0 && arr[parent(index)] > arr[index]){
        int temp = arr[index];
        arr[index] = arr[parent(index)];
        arr[parent(index)] = temp;
        index = parent(index);
    }
}

void MinHeap::printHeap(){
    cout << "\nHeap: ";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
	int arr[]={10,11,20,19};
	MinHeap h(arr,4, 15);
    h.printHeap();
    cout << "Mix ele " << h.getMin() << "\n";
    h.insertKey(3); 
    h.insertKey(2); 
    h.printHeap();
    h.deleteKey(1); 
    h.printHeap();
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45);
    h.printHeap();
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    h.printHeap();
    h.decreaseKey(2, 1); 
    h.printHeap();
    cout << h.getMin(); 
    h.decreaseKey(4, 2); 
    h.printHeap();
    cout << h.getMin(); 
	return 0;
}