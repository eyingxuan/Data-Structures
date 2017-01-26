#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;
struct UFDS{
private: 
	vi parent,rank;
	int n;
public: 
	UFDS(int x){
		n = x;
		rank.assign(n,0);
		parent.assign(n,0);
		for (int i = 0 ; i < n ;i++){
			parent[i] = i;
		}
	}
	int findSet(int i){
		return p[i] == i ? i : p[i] = findSet(p[i]);
	}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j){
		if (!isSameSet(i,j)){
			int x = findSet(i);
			int y = findSet(j);
			if (rank[x] > rank[y]){
				parent[x] = y;
			}
			else{
				parent[y] = x;
				if (rank[x] == rank[y]){
					rank[y]++;
				}
			}
		}
	}
};
int main(){
	
}