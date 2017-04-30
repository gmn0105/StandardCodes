#include<iostream>
#include<cmath>
using namespace std ;

// This function computes the highest power of prime p that divides n!

int fact_wrt_prime(int n, int p) {
	int ans = 0 ;
	for (int j = p; n/j != 0; j *= p) {
		ans += n/j ;
	//	cout << "j : " << j << " ans : " << ans << endl ;
	}
	return ans ;
}

int main () {
	int number, prime, answer ;
	cin >> number >> prime ;
	answer = fact_wrt_prime(number, prime) ;
	cout << answer ;
	return 0 ;
}
