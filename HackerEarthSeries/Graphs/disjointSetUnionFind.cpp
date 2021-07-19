#include <bits/stdc++.h>
using namespace std;

int performFind(vector<int> &parent, int node) {
	if(parent[node]==-1)
		return node;
	return parent[node]=performFind(parent, parent[node]);
}

void performUnion(vector<int> &parent, vector<int> &rank, int from, int to) {
	if(rank[from]==rank[to]) {
		parent[from]=to;
		rank[to]++;
	} else if(rank[from] > rank[to])
		parent[to]=from;
	else
		parent[from]=to;
}

bool isCyclic(int V, vector<vector<int>> &edges) {
	vector<int> parent(V, -1), rank(V, 0);
	for(auto edge : edges) {
		int from = edge[0];
		int to = edge[1];
		int Pfrom = performFind(parent, from);
		int Pto = performFind(parent, to);
		if(Pfrom==Pto)
			return true;
		performUnion(parent, rank, Pfrom, Pto);
	}
	return false;
}

int main() {
	int V,E;
	cin>>V>>E;
	vector<vector<int>> edges;
	int from,to;
	for(int i=0;i<E;i++) {
		cin>>from>>to;
		edges.push_back({from, to});
	}
	if(isCyclic(V, edges))
		cout<<"Cycle Detected"<<"\n";
	else
		cout<<"No Cycle Detected"<<"\n";
	return 0;
}

/*
With Cycle
5
5
0 1
2 3
1 2
0 4
4 3

Without Cycle
5
4
0 1
2 3
1 2
0 4

*/