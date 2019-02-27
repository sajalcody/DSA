#include <iostream>
#include <string> // memcpy
using namespace std;

class Array{
    public:
    int *a;
    int size;
    int capacity;

    Array (){
        capacity = 1;
        size = 0;
        a = new int[capacity];
    }
    Array (int c){
        capacity = c;
        size = 0;
        a = new int[capacity];
    }
    void append (int value);
    void insert(int value, int index);
    void remove();
    void removeI(int index);
    void doubleArray();
    void printArray();
};

void Array::doubleArray(){
    cout << "Array being doubled\n";
    capacity *= 2;
    int *newArr = new int[capacity];
    memcpy(newArr, a, (capacity/2) * sizeof(int));
    delete [] a;
    a = newArr;
}

void Array::append(int value){
    if(size + 1 > capacity)
        doubleArray();
    a[size++]= value;
    cout << "appended " << value <<"\n";
}

void Array::insert(int value, int index){
    if(size + 1 > capacity)
        doubleArray();
    int i;
    for(i = size; i>index; i--)
        a[i] = a[i-1];
    a[i]=value;
    size++;
    cout << "appended " << value <<"\n";
}

void Array::remove(){
    if(!size){
        cout << "Underflow\n";
        return;
    }
    size--;
    cout << "removed " << a[size];
}

void Array::removeI(int index){
    if(!size){
        cout << "Underflow\n";
        return;
    }
    cout << "removing " << a[index];
    for(int i = index; i < size; i++)
        a[i] = a[i + 1];
    size--;
}

void Array::printArray(){
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main(){
    class Array array;
    array.append(1);
    array.append(2);
    array.append(3);
    array.append(4);
    array.printArray();
    array.remove();
    array.insert(-1,0);
    array.printArray();
}