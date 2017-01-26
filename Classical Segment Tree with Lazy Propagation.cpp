#include <bits/stdc++.h>
using namespace std;

vector <int> a;
vector <int> st;
vector <int> lazy;
int n;
/*
Classical Segment Tree for RSQ with LAZY PROPAGATION
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

/*
Update Function
Given index of element, update lazy value based on how big the range is
*/

void upd(int id, int l, int r, int x){
	lazy[id]+= x;
	st[id] += (r-l)*x;
}

/*
Shift Function
Given index of element, shift lazy value to child. Uses update function to update child.
*** Notice that total value for updating the child is halved, sinced mid - l = (r-l)/2
*** THIS DOES NOT UPDATE ANYTHING, BUT MERELY PASSES ON THE LAZY VALUE
*/

void shift(int id, int l, int r){
	int mid = (l+r)/2;
	upd(id*2,l,mid,lazy[id]);
	upd(id*2 + 1 ,mid ,r,lazy[id]);
	lazy[id] = 0;
}

void increase(int x,int y,int v,int idx = 1, int l = 0, int r = n){
	if (x >= r or y <=l){return ;}
	if (x <= l and r <= y){
		upd(idx,l,r,v);
		return;
	}
	shift(idx,l,r);
	int mid = (l+r)/2;
	increase(x,y,v,idx*2,l,mid);
	increase(x,y,v,idx*2+1,mid,r);
	st[idx] = st[idx*2] + st[idx*2+1];
}

int sum(int x,int y,int idx = 1, int l = 0, int r= n){
	if (x>=r or y <=l){return 0;}
	if (x<= l and r <= y){
		return st[idx];
	}
	shift(idx,l,r);//THIS PASSES DOWN ANY LAZY VALUE, NOT UPDATE
	int mid = (l+r)/2;
	return (sum(x,y,idx*2,l,mid) + sum(x,y,idx*2+1,mid,r));
}
int main(){
	int arr[7] = {1,3,5,3,4,5,1};
	n = 7;
	/*for (int i = 0 ; i < n ;i++){
		a.push_back(arr[i]);
	}*/
	a.assign(arr,arr+7);

	st.assign(4*n,0);
	lazy.assign(4*n,0);
	
	build();
	//increase(1,3,2);
	//cout << sum(0,3);
	
}