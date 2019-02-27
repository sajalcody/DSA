#include <iostream>
#include <cstring>
#define MAX_VAL 1000005
using namespace std;

int prime[MAX_VAL];
int primes[MAX_VAL];
void soe(){
	int k = 1;
	memset(prime, 1, MAX_VAL);
	for(int p = 2; p < MAX_VAL; p++){
		if(prime[p]){
			//cout << p <<" ";
			primes[k++] = p;
			for(int i = p*p; i < MAX_VAL; i+=p)
				prime[i] = 0;
		}
	}
	cout << k <<" prime numbers till " << MAX_VAL <<"\n";
}
int main() {
	// your code goes here
	int n,t;
	cin >> t;
	
	soe();
	cout << endl;
	while (t--){
		cin >> n;
	cout << primes[n]<<" ";
	}
	return 0;
}
