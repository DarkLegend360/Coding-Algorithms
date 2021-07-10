#include <bits/stdc++.h>
using namespace std;

#define UNVISITED 0
#define VISITING 1
#define VISITED 2


bool checkForCycle(vector<vector<int>> graph, vector<int> &status, int vertex) {
    if(status[vertex]==VISITING)
        return true;
    status[vertex]=VISITING;
    for(auto neighbour : graph[vertex])
        if(status[neighbour]!=VISITED && checkForCycle(graph, status, neighbour))
            return true;
    status[vertex]=VISITED;
    return false;
}

bool hasCycle(vector<vector<int>> graph) {
    vector<int> status(graph.size(),UNVISITED);
    bool flag=true;
    for(int i=0;i<graph.size()&&flag;i++) {
        if(status[i]==UNVISITED && checkForCycle(graph, status, i))
            return true;
    }
    return false;
}

int main() {
    vector<vector<int>> graph = {{1,2},{},{3,4},{5},{},{}};
    cout<<hasCycle(graph)<<endl;
    return 0;
}