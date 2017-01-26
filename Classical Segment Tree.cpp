#include <bits/stdc++.h>
using namespace std;

vector <int> a;
vector <int> st;
int n;
/*
Classical Segment Tree for RSQ
1. When building the tree, the index used is [l,r), NOT INCLUSIVE OF R
2. Similarly, when performing RSQ, the query range is [i,j), NOT INCLUSIVE OF J
3. ST uses 1-based indexing while A using 0-based indexing
*/

void build(int idx = 1, int l = 0, int r = n){
	if (r-l < 2){
		st[idx] = a[l];
		return;
	}
	int mid = (l+r)/2;

	build(idx*2, l, mid);
	build(idx*2 + 1, mid, r);
	st[idx] = st[idx*2] + st[idx*2+1];
}

void modify(int p, int x, int idx = 1, int l = 0, int r = n){
	st[idx] += x - a[p];
	if (r-l < 2){
		a[p] = x;
		return;
	}
	int mid = (l+r)/2;
	if (p < mid){
		modify(p,x,idx*2,l,mid);
	}
	else{
		modify(p,x,idx*2 + 1, mid, r);
	}
}

int sum(int i, int j, int idx = 1, int l = 0 , int r = n){
	if (i >= r or l >= j){return 0;}
	if (i <= l and r <= j){return st[idx];}
	int mid = (l+r)/2;
	return (sum(i,j,idx *2,l,mid) + sum(i,j,idx*2 + 1,mid,r));
}
int main(){
	int arr[5] = {1,3,5,6,8};
	n = 5;
	/*for (int i = 0 ; i < n ;i++){
		a.push_back(arr[i]);
	}*/
	a.assign(arr,arr+n);

	st.assign(4*n,0);
	
	build();
	//modify(0,5);
	//cout << sum(0,2) << endl;
	/*for (int i = 0 ; i < st.size() ; i++){
		cout << st[i] <<endl;
	}*/
	modify(2,66);
	cout << sum(2,3) << endl;
	//cout << sum(1,3) << endl;
}