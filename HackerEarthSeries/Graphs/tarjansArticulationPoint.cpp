#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>
#define vb vector<bool>

void dfs(vvi &graph, vi &disc, vi &low, vi &parent, vb &AP, int curNode) {
	static int time =0;
	disc[curNode] = low[curNode] = time++;
	int children=0;
	for(auto neighbour : graph[curNode]) {
		if(disc[neighbour]==-1) {
			parent[neighbour]=curNode;
			children++;
			dfs(graph, disc, low, parent, AP, neighbour);
			low[curNode]=min(low[curNode], low[neighbour]);

			if(parent[curNode]==-1 && children>1)
				AP[curNode]=true;
			if(parent[curNode]!=-1 && low[neighbour]>=disc[curNode])
				AP[curNode]=true;
		} else if(neighbour!=parent[curNode])
			low[curNode]=min(low[curNode], disc[neighbour]);
	}
}

void tarjansAlgorithm(vector<vector<int>> &graph) {
	int V = graph.size();
	vector<int> disc(V, -1), low(V, -1), parent(V, -1);
	vector<bool> AP(V,false);
	for(int i=0;i<V;i++)
		if(disc[i]==-1)
			dfs(graph, disc, low, parent, AP, i);
	for(int i=0;i<V;i++)
		if(AP[i])
			cout<<i<<"\n";
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
6
6
0 1
1 2
0 2
0 3
3 4
3 5
*/