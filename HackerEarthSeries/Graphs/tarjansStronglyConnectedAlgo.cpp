#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define vi vector<int>
#define vb vector<bool>

void dfs(vvi &graph, vi &disc, vi &low, stack<int> &st, vb &inStack, int curNode) {
	static int time=0;
	disc[curNode] = low[curNode] = time++;
	st.push(curNode);
	inStack[curNode]=true;
	for(auto neighbour : graph[curNode]) {
		if(disc[neighbour]==-1) {
			dfs(graph, disc, low, st, inStack, neighbour);
			low[curNode]=min(low[curNode], low[neighbour]);
		} else if(inStack[neighbour])
			low[curNode]=min(low[curNode], disc[neighbour]);
	}
	if(disc[curNode]==low[curNode]) {
		while(st.top()!=curNode) {
			cout<<st.top()<<" ";
			inStack[st.top()]=false;
			st.pop();
		}
		cout<<st.top()<<"\n";
		inStack[st.top()]=false;
		st.pop();
	}
}

void tarjansAlgorithm(vector<vector<int>> &graph) {
	int V = graph.size();
	vector<int> disc(V, -1), low(V, -1);
	vector<bool> inStack(V,false);
	stack<int> st;
	for(int i=0;i<V;i++)
		if(disc[i]==-1)
			dfs(graph, disc, low, st, inStack, i);
}

int main() {
	int V, E;
	cin>>V>>E;
	vector<vector<int>> graph(V, vector<int>{});
	int from, to;
	for(int i=0;i<E;i++) {
		cin>>from>>to;
		graph[from].push_back(to);
	}
	tarjansAlgorithm(graph);
	return 0;
}

/*
7
10
0 1
1 2
1 3
3 4
4 5
4 6
4 0
5 6
6 5
5 2
*/