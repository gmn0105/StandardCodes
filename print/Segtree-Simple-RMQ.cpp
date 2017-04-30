#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#define REP(i,x,y) for(int i = x; i<=y; i++)
using namespace std;
int a[1000009] = {0};		// stores input data. Starts from a[1].
int st[10000010];			// stores segtree, starts from st[1]. In general size of st = 4 * size of input.
int maximum = 0; 			// problem specific!

//This build function works for finding min in [l,r].
void build_st(int node, int start, int end) {
	// takes O(n)
	// node is current node in st. start, end of the corresponding interval in a[].
	
	if(start == end) st[node] = a[start]; 	// reached leaf
	
	else {
		int mid = (start+end)/2;
		build_st(2*node, start, mid);
		build_st(2*node+1, mid+1, end);
		
		//---------------CAN EDIT THIS PART ONLY---------------------
		
		st[node] = min(st[2*node],st[2*node+1]); 	// this will depend on the problem
		
		//-----------------------------------------------------------
		
	}
	
}

//This query function works for finding sum of [l,r].
int query_st(int node, int start, int end, int l, int r) {
	// takes O(log(n))
	// start, end for recursion. l, r are query inputs.
	//---------------CAN EDIT RETURN VALUES ONLY---------------------
	
	if(start>r || end<l) {
		// search interval completely outside [l,r]
		return maximum;
	}
	
	else if(l<=start && end<=r) {
		//search interval completely inside [l,r]
		return st[node];
	}
	
	// search interval partially inside [l,r]
	int mid = (start+end)/2;
	
	int m1 = query_st(2*node, start, mid, l, r);
	int m2 = query_st(2*node+1, mid+1, end, l, r);
	
	return min(m1,m2);
	
	/*if(l==start&&r==end) {
		return a[start];
	}
	
	int mid = (start+end)/2;
	
	if(r<=mid) {
		return query_st(2*node, start, mid, l, r);
	}
	
	if(l>mid) {
		return query_st(2*node+1, mid+1, end, l, r);
	}
	
	int m1 = query_st(2*node, start, mid, l, r);
	int m2 = query_st(2*node+1, mid+1, end, l, r);
	
	return min(m1,m2);*/
	
	//-----------------------------------------------------------
}


int main() {
	int n;			// size of input data array
	cin >> n;
	
	REP(i,1,n) {
		cin >> a[i];
		if(a[i]>maximum) maximum = a[i];
	}
	
	build_st(1,1,n);
	
	int q;			// number of GET queries
	cin >> q;
	
	while(q-->0) {
		
		int query_l, query_r; 		// stores left and right limits of query interval
		cin >> query_l >> query_r;
		
		cout << query_st(1, 1, n, query_l+1, query_r+1) << endl; // MUST account for 1 indexed a[]
		
	}
	
	return 0;
}
