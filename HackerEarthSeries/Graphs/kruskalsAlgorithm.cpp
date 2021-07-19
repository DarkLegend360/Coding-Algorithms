#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

class Edge  {
	public:
	int from;
	int to;
	int weight;
	Edge(int from, int to, int weight) {
		this->from=from;
		this->to=to;
		this->weight=weight;
	}
};

bool comp(Edge e1, Edge e2) {
	return e1.weight<e2.weight;
}

int performFind(vi &parent, int vertex) {
	if(parent[vertex]==-1)
		return vertex;
	return parent[vertex]=performFind(parent, parent[vertex]);
}

void performUnion(vi &parent, vi &rank, int from, int to) {
	if(rank[from]==rank[to]) {
		parent[from]=to;
		rank[to]++;
	} else if(rank[from]>rank[to])
		parent[to]=from;
	else
		parent[from]=to;
}

void kruskalsAlgorithm(vector<Edge> &edges, int V) {
	vector<Edge> result;
	int E = edges.size();
	sort(edges.begin(), edges.end(), comp);
	vector<int> rank(V, 0);
	vector<int> parent(V, -1);
	for(int i=0,j=0;i<(V-1)&&j<E;) {
		int from = edges[j].from;
		int to = edges[j].to;
		int fromAP =  performFind(parent, from);
		int toAP = performFind(parent, to);
		if(fromAP==toAP) {
			j++;
			continue;
		}
		performUnion(parent, rank, fromAP, toAP);
		i++;
		result.push_back(edges[j]);
	}
	for(auto edge : result)
		cout<<edge.from<<" "<<edge.to<<" "<<edge.weight<<"\n";
}

int main() {
	int V,E;
	cin>>V>>E;
	vector<Edge> edges;
	int from, to, weight;
	for(int i=0;i<E;i++) {
		cin>>from>>to>>weight;
		edges.push_back(Edge(from, to, weight));
	}
	kruskalsAlgorithm(edges, V);
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

OUTPUT

2 3 1
3 4 2
1 3 3
3 5 3
0 1 4

*/