#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

long long int pow(long long int a, long long int b, long long int MOD)
	{
	long long int x=1,y=a; 
	while(b > 0)
	{
	if(b%2 == 1)
	{
	x=(x*y);
	if(x>MOD) x%=MOD;
	}
	y = (y*y);
	if(y>MOD) y%=MOD; 
	b /= 2;
	}
	return x;
	}

int main() {
	int long long mod = pow(10,9) + 7;
	int long long a, t, num, power;
	cin >> t;
	while(t>0) {
		cin >> a >> power;
		int long long power_of_a[10010];
		power_of_a[0] = a;
		for(int i = 1; i < 10010; i++) {
			power_of_a[i] = (power_of_a[i-1]*power_of_a[i-1])%mod;
		}
		/*for(int i = 0; i<13; i++) {
			cout << "i: " << i << " power_of_a: " << power_of_a[i] << endl;
		}*/
		// num = pow(2,power,mod);
		num = 1;
		for(int j = 0; power >= 1<<j; j++) {
			/*cout << "j: " << j << endl;
			bool h = power&1<<j;
			cout << "power&j: " << h << endl;*/
			if(power&1<<j) num = (num*power_of_a[j])%mod;
			//cout << "num: " << num << endl;
		}
		cout << num << endl;
		t--;
	}
    return 0;
}
