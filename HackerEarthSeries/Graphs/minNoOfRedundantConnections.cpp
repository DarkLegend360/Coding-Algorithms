#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>

void dfs(vvi &graph, vi &visited, int curNode) {
	visited[curNode]=true;
	for(auto neighbour : graph[curNode])
		if(!visited[neighbour])
			dfs(graph, visited, neighbour);
}

int minNoOfRedundantConnections(vvi &graph, int edges) {
	int components=0;
	vector<int> visited(graph.size(), false);
	for(int i=0;i<graph.size();i++)
		if(!visited[i]) {
			components++;
			dfs(graph, visited, i);
		}
	int mstNodes = graph.size()-1;
	if(edges<mstNodes)
		return -1;
	return components-1;
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
	cout<<minNoOfRedundantConnections(graph, E)<<"\n";
	return 0;
}

/*
6
7
0 1
1 2
2 3
3 0
0 2
1 3
4 5

answer is 1
*/