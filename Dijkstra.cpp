#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <vector <pair <ll,ll>>> adjL(100005);
bool visited[100005];
ll dist[100005];
/*
Dijkstra's Algorithm to find Shortest Path and Path Length
Solves Alpha Round #2 C Codeforces Directly
Simple Priority Queue Pair Implementation
*/
int main(){
	memset(visited,0,sizeof(visited));
	fill(dist,dist+100005,LLONG_MAX);
	ll n,m;
	cin >> n >> m;
	long long s;
	s = 1;
	dist[s] = 0;
	for (long long i = 0 ; i < m ; i++){
		long long u,v,weight;
		cin >> u >> v >> weight;
		adjL[u].push_back(make_pair(weight,v));
		adjL[v].push_back(make_pair(weight,u));
	}
	//cout << "HI" << endl;
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
	pq.push(make_pair(dist[s],s));
	while(!pq.empty()){
		long long x = pq.top().second;
		//cout <<"x" <<x << endl;
		pq.pop();
		if (!visited[x]){
			visited[x] = true;
			for (auto i : adjL[x]){
				if (dist[i.second] > dist[x] + i.first){
					dist[i.second] = dist[x] + i.first;
					//cout << dist[i.second] << endl;
					pq.push(make_pair(dist[i.second],i.second));
				}
			}
		}
	}
	vector <int> vertices;
	if (dist[n] == LLONG_MAX){
		cout << -1 << endl;
	}
	else{
		int current = n;
		//vertices.push_back(current);
		vertices.push_back(n);
		while(dist[current] != 0){
			//cout << "HI" << endl;
			//cout << "current" << endl;
			for (auto i:adjL[current]){
				//cout << "vertex " << i.second << endl;
				//cout << dist[current] << endl;
				//cout << i.first << endl;
				//cout << dist[i.second] << endl;
				if (dist[current] - i.first == dist[i.second]){
					current = i.second;
					//cout << current << endl;
					vertices.push_back(current);
					//cout << current << endl;
					break;
					
				}
			}
			//cout << "once" << endl;
		}
		//vertices.push_back(s);
		for (int i = vertices.size()-1; i >= 0; i--){
			cout << vertices[i] << " ";
		}
		cout << endl;
		

		//cout << dist[n] << endl;
	}


	
}