#include <bits/stdc++.h>
using namespace std;

bool isNodeInCycle(vector<vector<int>> edges, vector<int> &state, int vertex) {
    if(state[vertex]==1)
        return true;
    if(state[vertex]==2)
        return false;
    state[vertex]=1;
    for(auto edge : edges[vertex])
        if(isNodeInCycle(edges, state, edge))
            return true;
    state[vertex]=2;
    return false;
}

bool cycleInGraph(vector<vector<int>> edges) {
    int numberOfNodes=edges.size();
    vector<int> state(numberOfNodes,0);
    for(int vertex=0;vertex<numberOfNodes;vertex++) {
        if(state[vertex]==2)
            continue;
        for(auto edge : edges[vertex])
            if(isNodeInCycle(edges, state, edge))
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