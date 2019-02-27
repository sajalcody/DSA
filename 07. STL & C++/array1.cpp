//EXPERIMENTS WITH ARRAYS
#include <iostream>
#include <string.h> // memset
using namespace std;

int g[5];

void  array_1D_initialisation() {
	int a[5], b[5] = {0}, c[5] = {-1}, d[5] = {1}, e[5];

    cout << "Default Initialisation\n";
	for(int i = 0; i < 5; i++) // DEAFULT VALUE OF 1D ARRAY IS 0
	    cout << a[i] <<" ";
	cout << endl;
	for(int i = 0; i < 5; i++) // ARRAY CAN ONLY BE INITALISED TO 0 ALTOGETHER
	cout << b[i] <<" ";
	cout << endl;
	for(int i = 0; i < 5; i++)  // FOR ANY OTHER VALUE ONLY FIRST VALUE IS INITIALISED(HERE -1), ALL OTHER TO 0
	cout << c[i] <<" ";
	cout << endl;
	for(int i = 0; i < 5; i++)  // FOR ANY OTHER VALUE ONLY FIRST VALUE IS INITIALISED(HERE 1), ALL OTHER TO 0
	cout << d[i] <<" ";
	cout << endl;
	for(int i = 0; i < 5; i++)  // BUT E IS INITIALISED TO GARBAGE
	cout << e[i] <<" ";
	cout << endl;
	for(int i = 0; i < 5; i++) // GLOBAL 1D ARRAY ARE INIT TO 0
	cout << g[i] <<" ";
	cout << endl;
}

void array_2D_initialisation(){
    int a[2][2]={0}, b[2][2]={-1}, c[2][2]={1}, d[4][2], e[2][2];
    memset(e, -1, sizeof(e));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j <2; j++)
            cout << a[i][j]<<" , ";
        cout << " :: ";
    }
    cout << endl;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j <2; j++)
            cout << b[i][j]<<" , ";
        cout << " :: ";
    }
    cout << endl;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j <2; j++)
            cout << c[i][j]<<" , ";
        cout << " :: ";
    }
    cout << endl;
    cout << "Default Initialisation\n";
    for(int i = 0; i < 4; i++){
        for(int j = 0; j <2; j++)
            cout << d[i][j]<<" , ";
        cout << " :: ";
    }
    cout << endl;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j <2; j++)
            cout << e[i][j]<<" , ";
        cout << " :: ";
    }
    cout << endl;
}

int main(){

    // array_1D_initialisation();
    array_2D_initialisation();

}