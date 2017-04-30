#include<iostream>
#include<cmath>
#include<vector>
using namespace std ;

void sieve(int n, vector<int> &primes) {
	for (int i = 2; i < n+1; i++) {
		while (primes[i] == 0) i++ ;
		for (int j = i+primes[i]; j < n+1; j += primes[i]) {
			primes[j] = 0 ;
		}
	}
}

int main () {
	int n ;
	cin >> n ;
	vector<int> primes(n+1, 0) ;
	for (int i = 1; i < n+1; i++) {
		primes[i] = i ;
	}
	sieve(n, primes) ;
	for (int i = 0; i < n+1; i++) {
		cout << primes[i] << endl ;
	}
	return 0 ;
}
