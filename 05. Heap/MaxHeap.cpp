#include <iostream>
#include <limits.h> // INT_MAX
using namespace std;

/* PROPERTIES OF HEAP
Height of Heap(h): (lg n)
Min Nodes in Heap: 2^h
Max Nodes in Heap: 2^(h+1)-1
*/

class MaxHeap {
	int *arr;
	int capacity;
	int heap_size;
	// int heap_type; //Min_Heap or Max_Heap Optional
	 public:

	 MaxHeap (int capacity);
	 MaxHeap(int capacity, int intialArr[], int size);

	 int parent (int i){
	 	return (i-1)/2;}
	 int left(int i){
	 	return 2 * i + 1;} // 2 << i + 1
	 int right(int i){
	 	return 2 * i + 2;}
	 
     // maxHeapify is the key to maintain the maxheap property
	 void maxHeapify(int); // => O(lg n)
    // buildMaxHeap produces a max heap from an unordered input array
     void buildMaxHeap(); // => O(n)

	 int extractMax(); // Delete the max Element O(lg n)
	 int getMax();   // get the value of max element O(1)
	 
	void insertKey(int k); // => O(lg n)
	void deleteKey(int i); // => O(lg n)
	void decreaseKey(int i, int newVal); // Optional => O(lg n)

    void printHeap(); //Not required
};

MaxHeap::MaxHeap(int c){
	heap_size=0;
	capacity=c;
	arr=new int[capacity];
}

MaxHeap::MaxHeap(int c, int a[], int size){
	arr=new int[c];
	for(int i = 0; i < size; i++)
	    arr[i] = a[i];
	// arr=a; => GIVE SEGMENTATION FAULT
	heap_size=size;
	capacity = c;
	buildMaxHeap();
}

void MaxHeap::maxHeapify(int i){ // => O(lg n)
	int l = left(i), r = right(i), largest = i;
	if(l < heap_size && arr[l] > arr[i])
	largest = l;
	if(r < heap_size && arr[r] > arr[largest])
	largest = r;
	if (largest != i){
		int temp=arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		maxHeapify(largest);
	}
}

void MaxHeap::buildMaxHeap(){ // => O(n)
    for(int i=(heap_size - 1)/2; i >= 0; i--)
		maxHeapify(i);
}

/* Iterative maxHeapify
void MaxHeap::maxHeapify(int i){ // => O(lg n)
    while(i < heap_size){
	    int l = left(i), r = right(i), largest = i;
        if(l < heap_size && arr[l] > arr[i])
        largest = l;
        if(r < heap_size && arr[r] > arr[largest])
        largest = r;
        if (largest != i){
            int temp=arr[largest];
            arr[largest] = arr[i];
            arr[i] = temp;
            i = largest;
        }
        else return;
    }
}
*/

int MaxHeap::getMax(){ // => O(1)
	return arr[0];
}

int MaxHeap::extractMax(){ // => O(lg n)
	if (heap_size < 1)
		return INT_MIN;
	int max=arr[0];
	arr[0] = arr[heap_size - 1];
	heap_size--;
	maxHeapify(0);
	return max;
}

void MaxHeap::insertKey(int k){ // => O(lg n)
	if(heap_size == capacity){
		cout <<" Overflow";
		return;
	}
	int i = heap_size++;
	arr[i] = k;
	while(i !=0 && arr[parent(i)] < arr[i]){
		int temp = arr[parent(i)];
		arr[parent(i)] = arr[i];
		arr[i] = temp;
		i = parent(i);
	}
}
void MaxHeap::deleteKey(int i){ // => O(lg n)
	if(i >= heap_size){
		cout << "Index does not exist";
		return;
	}
	arr[i] = arr[--heap_size];
	maxHeapify(i);
}

void MaxHeap::decreaseKey(int i, int newVal){ // => O(lg n)
	if(i >= heap_size){
		cout << "Index does not exist";
		return;
	}
	arr[i] = newVal;
	maxHeapify(i);
}

void MaxHeap::printHeap(){
    cout << "\nHeap: ";
    for(int i = 0; i < heap_size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
	int arr[]={10,11,20,19};
	MaxHeap h(15, arr,4);
    h.printHeap();
    cout << "Max ele " << h.getMax() << "\n";
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
    cout << h.extractMax() << " "; 
    cout << h.getMax() << " "; 
    h.printHeap();
    h.decreaseKey(2, 1); 
    h.printHeap();
    cout << h.getMax(); 
	return 0;
}