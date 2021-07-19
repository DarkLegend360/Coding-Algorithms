#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<pair<int,int>>>
#define vi vector<int>
#define pr pair<int,int>

void primsAlgorithm(vvi &graph, int source) {
	int V = graph.size();
	vector<int> parent(V, -1);
	vector<bool> setMST(V, false);
	vector<int> minCost(V, INT_MAX);
	minCost[source]=0;
	priority_queue<pr, vector<pr>, greater<pr>> pq;
	pq.push({0, source});
	while(!pq.empty()) {
		int minNode = pq.top().second;
		pq.pop();
		if(setMST[minNode])
			continue;
		setMST[minNode]=true;
		for(auto neighbourNode : graph[minNode]) {
			int weight = neighbourNode.second;
			int neighbour = neighbourNode.first;
			if(!setMST[neighbour] && weight<minCost[neighbour]) {
				parent[neighbour]=minNode;
				minCost[neighbour]=weight;
				pq.push({weight, neighbour});
			}
		}
	}
	for(int i=0;i<graph.size();i++)
		if(parent[i]!=-1)
			cout<<parent[i]<<"->"<<i<<"   :"<<minCost[i]<<endl;
}

int main() {
	int V, E;
	cin>>V>>E;
	vector<vector<pair<int,int>>> graph(V, vector<pair<int,int>>{});
	int from, to, weight;
	for(int i=0;i<E;i++) {
		cin>>from>>to>>weight;
		graph[from].push_back({to, weight});
		graph[to].push_back({from, weight});
	}
	int source;
	cin>>source;
	primsAlgorithm(graph, source);
	return 0;
}

/*
6
9
0 1 4
0 2 6
1 2 6
1 4 4
1 3 3
2 3 1
3 4 2
4 5 7
3 5 3
0
*/