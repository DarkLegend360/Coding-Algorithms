#include <bits/stdc++.h>
using namespace std;
#define NO_COLOR 0
#define RED 1
#define WHITE 2

int oppositeColor(vector<int> &coloring, int vertex) {
  	return coloring[vertex]==RED?WHITE:RED;
}
bool isBipartite(vector<vector<int>>& adjList) {
  	vector<int> coloring(adjList.size(),0);
  	queue<int> myQueue;
  	unordered_set<int> visited;
  	for(int i=0;i<adjList.size();i++) {
    	if(visited.find(i)==visited.end()) {
	      	int start=i;
	      	coloring[start]=RED;
	      	myQueue.push(start);
	      	visited.insert(start);
	      	while(!myQueue.empty()) {
	        	int vertex = myQueue.front();
	        	myQueue.pop();
	        	for(int adj : adjList[vertex]) {
		          	int adjColor = coloring[adj];
		          	if(adjColor==NO_COLOR)
		            	coloring[adj]=oppositeColor(coloring, vertex);
		          	else if(adjColor==coloring[vertex])
		            	return false;
		          	if(visited.find(adj)==visited.end()) {
		            	visited.insert(adj);
		            	myQueue.push(adj);
		          	}
        		}
      		}
    	}
  	}
  	return true;
}

int main() {
	return 0;
}