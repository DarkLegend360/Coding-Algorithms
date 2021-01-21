#include <bits/stdc++.h>
using namespace std;

bool isNodeInCycle(vector<vector<int>> edges, vector<bool> &visited, vector<bool> visiting, int vertex) {
    if(visiting[vertex])
        return true;
    if(visited[vertex])
        return false;
    visited[vertex]=true;
    visiting[vertex]=true;
    for(auto edge : edges[vertex])
        if(isNodeInCycle(edges, visited, visiting, edge))
            return true;
    visiting[vertex]=false;
    return false;
}

bool cycleInGraph(vector<vector<int>> edges) {
    int numberOfEdges=edges.size();
    vector<bool> visited(numberOfEdges,false);
    vector<bool> visiting(numberOfEdges,false);
    for(int vertex=0;vertex<numberOfEdges;vertex++) {
        if(visited[vertex])
            continue;
        for(auto edge : edges[vertex])
            if(isNodeInCycle(edges, visited, visiting, edge))
                return true;
    }
    return false;
}


int main() {
    vector<vector<int>> input = {{1, 3}, {2, 3, 4}, {0}, {}, {2, 5}, {}};
    auto expected = true;
    auto actual = cycleInGraph(input);
    cout<<(expected == actual)<<endl;
}