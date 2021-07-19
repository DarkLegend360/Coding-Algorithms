#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>

void dfs(vvi &graph, vi &disc, vi &low, vi &parent, vvi &bridges, int curNode) {
	static int time=0;
	low[curNode] = disc[curNode] = time++;
	for(auto neighbour : graph[curNode]) {
		if(parent[neighbour]==-1) {
			parent[neighbour]=curNode;
			dfs(graph, disc, low, parent, bridges, neighbour);
			low[curNode]=min(low[curNode], low[neighbour]);

			if(low[neighbour]>disc[curNode])
				bridges.push_back({curNode, neighbour});
		} else if(parent[curNode]!=neighbour)
			low[curNode]=min(low[curNode], disc[neighbour]);
		
	}
}

void tarjansAlgorithm(vector<vector<int>> &graph) {
	int V = graph.size();
	vector<int> disc(V, -1), low(V, -1), parent(V, -1);
	vector<vector<int>> bridges;
	for(int i=0;i<V;i++)
		if(disc[i]==-1)
			dfs(graph, disc, low, parent, bridges, i);
	for(auto bridge : bridges)
		cout<<bridge[0]<<" "<<bridge[1]<<"\n";
}

int main() {
	int V, E;
	cin>>V>>E;
	vector<vector<int>> graph(V, vector<int>{});
	int from, to;
	for(int i=0;i<E;i++) {
		cin>>from>>to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	tarjansAlgorithm(graph);
	return 0;
}

/*
5
5
0 1
1 2
0 2
0 3
3 4
*/