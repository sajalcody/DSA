#include <iostream>
using namespace std;

/* INSERTION SORT
-> in-place
-> Worst Case T: O(n²); reverse sorted
-> Average case T: O(n²)
-> Best Case T: O(n); sorted array
*/

int main(){
    int a[]={4, 2, 10, 8, 5, 9, 7, 8}, n = 8;
    for(int i=1; i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j >= 0 && a[j] > key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    for(int i=0; i<n;i++)
        cout << a[i] << " ";
    return 0;
}