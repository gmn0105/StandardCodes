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

//This is for problem of finding max sum of a subinterval in query range [l,r]
struct data {
	int l_sum = 0, r_sum = 0, sum = 0, best_sum = 0;
};

int a[100010];		 // 1 indexed
data st[4*100010];	 // 1 indexed

data merge(data l_data, data r_data) {
	// merge function to appropriately merge two segments
	data ans;
	ans.l_sum = max(l_data.l_sum, l_data.sum + r_data.l_sum);
	ans.r_sum = max(r_data.r_sum, r_data.sum + l_data.r_sum);
	ans.sum = l_data.sum + r_data.sum;
	ans.best_sum = max( max(l_data.best_sum, r_data.best_sum), l_data.r_sum+r_data.l_sum );
	return ans;
}

data create(int val) {
	data ans;
	ans.sum = ans.l_sum = ans.r_sum = ans.best_sum = val;
	return ans;
}

void build_st(int node, int start, int end) {
		
	if(start == end) {
		 st[node] = create(a[start]);
	}
	else {
		int mid = (start+end)/2;
		build_st(2*node, start, mid);
		build_st(2*node+1, mid+1, end);
		st[node] = merge(st[2*node], st[2*node+1]);
	}
	
}

void update_st(int node, int start, int end, int l, int r) {
	
	if(start == end) {
		// make changes to leaves
	}
	
	else {
		int mid = (start+end)/2;
		if(r<=mid){
			update_st(2*node, start, mid, l, r);
		}
		else if(l>mid) {
			update_st(2*node+1, mid+1, end, l, r);
		}
		else {
			update_st(2*node, start, mid, l, r);
			update_st(2*node+1, mid+1, end, l, r);
		}
		st[node] = merge(st[2*node], st[2*node+1]);
	}
	
}

data query_st(int node, int start, int end, int l, int r) {
	//cout << "query s,e: " << start << " " << end << endl;
	if(start>r || end<l) {
		// search interval completely outside [l,r]
		return create(0);
	}
	
	else if(l<=start && end<=r) {
		//search interval completely inside [l,r]
		return st[node];
	}
	
	// search interval partially inside [l,r]
	int mid = (start+end)/2;
	
	if(r<=mid) {
		return query_st(2*node, start, mid, l, r);
	}
	if(l>mid) {
		return query_st(2*node+1, mid+1, end, l, r);
	}
	
	data m1 = query_st(2*node, start, mid, l, r);
	data m2 = query_st(2*node+1, mid+1, end, l, r);
	
	return merge(m1,m2);
	
}

int main() {
	int t;
	scanf("%d",&t);
	while(t-->0) {
		int n;
		scanf("%d",&n);
		REP(i,1,n) {
			scanf("%d", &a[i]);
		}
		
		build_st(1,1,n);
		
		int q;
		scanf("%d",&q);
		while(q-->0) {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if(x2 > y1) {
				int ans = query_st(1,1,n,x1,y1).r_sum + query_st(1,1,n,y1+1,x2-1).sum +  query_st(1,1,n,x2,y2).l_sum;
				printf("%d\n", ans);
			}
			else {
				int ans = max( query_st(1,1,n,x1,x2-1).r_sum + query_st(1,1,n,x2,y2).l_sum, max( query_st(1,1,n,x1,y1).r_sum + query_st(1,1,n,y1+1,y2).l_sum, query_st(1,1,n,x2,y1).best_sum )  );
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
