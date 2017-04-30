#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int n, a[1000009], st[10000010], maxi;

void build_st (int node, int start, int end) {
	if(start == end) st[node] = a[start];
	else {
		int mid = (start+end)/2;
		build_st(2*node, start, mid);
		build_st(2*node+1, mid+1, end);
		st[node] = min(st[2*node], st[2*node+1]);
	}
}

int query(int node, int start, int end, int l, int r) {
	//cout << "node, start, end, l, r: " << node << " " << start << " " << end << " " << l << " " << r << endl;
	if(start>r || end<l) {
		//cout << "completely outside, returning maxi: " << maxi << endl;
		return maxi;
	}
	if(l<=start && end<=r) {
		//cout << "completely inside, returning st[node]: " << st[node] << endl;
		return st[node];
	}
	int mid = (start+end)/2;
	int m1 = query(2*node, start, mid, l ,r), m2 = query(2*node+1, mid+1, end, l ,r);
	//cout << "partial, returning: " << min(m1,m2) << endl;
	return min(m1, m2);
}

int main() {
	int n;
	cin >> n;
	cin >> a[1];
	maxi = a[1];
	for(int i = 2; i<=n; i++) {
		cin >> a[i];
		if(a[i]>maxi) maxi = a[i];
	}
	build_st(1, 1, n);
	/*for(int i = 1; i<=n; i++) {
		cout << st[i] << " ";
	}
	cout << endl;*/
	int l, r, q;
	cin >> q;
	while(q--) {
		cin >> l >> r;
		cout << query(1, 1, n, l+1, r+1) << endl;
	}
    return 0;
}
