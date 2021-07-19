#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited) {
	visited[node]=true;
	for(auto neighbour : graph[node])
		if(!visited[neighbour])
			dfs(neighbour, graph, visited);
}
bool connectedComponent(vector<vector<int>> &graph) {
	int node=-1;
	vector<bool> visited(graph.size(), false);
	for(int i=0;i<graph.size();i++)
		if(graph[i].size()) {
			node=i;
			break;
		}
	if(node==-1)
		return true;
	dfs(node, graph, visited);
	for(int i=0;i<graph.size();i++)
		if(!visited[i] && graph[i].size())
			return false;
	return true;
}
void eulerCircuit(vector<vector<int>> &graph) {
	if(!connectedComponent(graph)) {
		cout<<"No Eular Circuit"<<"\n";
		return;
	}
	int odd=0;
	for(int i=0;i<graph.size();i++)
		if(graph[i].size()&1)
			odd++;
	if(odd==0)
		cout<<"Eular Circuit Exists"<<"\n";
	else if(odd==2)//else if(odd==1 || odd==2)
		cout<<"Semi-Euler Path Exists"<<"\n";
	else if(odd>2)
		cout<<"No Euler Circuit Exists"<<"\n";
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
	eulerCircuit(graph);
	return 0;
}

/*
Semi-Euler
5
5
0 1
1 2
2 3
2 4
3 4

Euler
3
3
0 1
1 2
2 0
*/