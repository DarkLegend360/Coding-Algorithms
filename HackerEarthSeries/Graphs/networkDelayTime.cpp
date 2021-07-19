#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<pair<int, int>>>
#define vi vector<int>


int networkDelayTime(vvi &graph, int target) {
	vector<int> minDistance(graph.size(), INT_MAX);
	queue<vector<int>> que;
	que.push({target, 0});
	minDistance[target]=0;

	while(!que.empty()) {
		int curDist = que.front()[1];
		int curNode = que.front()[0];
		que.pop();
		for(auto neighbourNode : graph[curNode]) {
			int neighbour= neighbourNode.first;
			int weight = neighbourNode.second;
			int newDist = curDist + weight;
			if(newDist<minDistance[neighbour]) {
				minDistance[neighbour]=newDist;
				que.push({neighbour, newDist});
			}
		}
	}
	for(auto x : minDistance)
		cout<<x<<" ";
	cout<<endl;
	int maxDist = *max_element(minDistance.begin(), minDistance.end());
	return maxDist;
}

int main() {
	int V, E;
	cin>>V>>E;
	vector<vector<pair<int, int>>> graph(V, vector<pair<int, int>>{});
	int from, to, weight;
	for(int i=0;i<E;i++) {
		cin>>from>>to>>weight;
		graph[from-1].push_back(make_pair(to-1, weight));
	}
	int target;
	cin>>target;
	int minDist = networkDelayTime(graph, target-1);
	if(minDist==INT_MAX) {
		cout<<-1<<endl;
		return 0;
	}
	cout<<minDist<<"\n";
	return 0;
}

/*
5
5
1 2 1
1 3 2
2 4 4
2 5 5
3 5 3
1

answer is 5
*/