#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
    int n, q, x, y, k;
    cin >> n;
    //cout << ceil(log2(n));
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    cin >> q;
    vector<vector<int>> m(n, vector<int>(ceil(log2(n)), 0));
    for(int i = 0; i < n; i++) {
    	m[i][0] = i;
    }
    for(int j = 1; (1<<j)<=n; j++ ) {
    	for(int i = 0; i+(1<<j)-1 < n; i++) {
    		if( a[m[i][j-1]] < a[m[i+(1<<(j-1))][j-1]] )
    			m[i][j] = m[i][j-1];
    		else
    			m[i][j] = m[i+(1<<(j-1))][j-1];
    	}
    }
    while(q>0) {
    	cin >> x >> y;
    	k = floor(log2(y-x+1));
    	if(a[m[x][k]] < a[m[y-(1<<k)+1][k]])
    		cout << a[m[x][k]] << endl;
    	else
    		cout << a[m[y-(1<<k)+1][k]] << endl;
    	q--;
    }
    return 0;
}
