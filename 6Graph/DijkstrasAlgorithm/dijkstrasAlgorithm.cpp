#include <bits/stdc++.h>
using namespace std;

vector<int> getCurrentMinVertexDistance(vector<int> minDistance,unordered_set<int> visited) {
    int minVertex=-1;
    int minDist=INT_MAX;
    for(int vertex=0;vertex<minDistance.size();vertex++) {
        if(visited.find(vertex)!=visited.end())
            continue;
        if(minDist>=minDistance[vertex]) {
            minDist=minDistance[vertex];
            minVertex=vertex;
        }
    }
    return {minVertex,minDist};
}

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
    int numberOfVerticles=edges.size();
    vector<int> minDistances(edges.size(),INT_MAX);
    minDistances[start]=0;
    unordered_set<int> visited;
    while(visited.size()!=numberOfVerticles) {
        vector<int> currentMinVertexDistance = getCurrentMinVertexDistance(minDistances,visited);
        int vertex = currentMinVertexDistance[0];
        int currentMinDistance =currentMinVertexDistance[1];
        if(currentMinDistance==INT_MAX)
            break;
        visited.insert(vertex);
        for(auto edge : edges[vertex]) {
            int destination = edge[0];
            int distanceToDestination = edge[1];
            if(visited.find(destination)!=visited.end())
                continue;
            int newPathDistance = currentMinDistance+distanceToDestination;
            int currentDestinationPath = minDistances[destination];
            if(newPathDistance<currentDestinationPath)
                minDistances[destination]=newPathDistance;
        }
    }
    for(int i=0;i<edges.size();i++)
        if(minDistances[i]==INT_MAX)
            minDistances[i]=-1;
    return minDistances;
}

int main() {
    vector<vector<vector<int>>> edges = {{{1, 7}}, {{2, 6}, {3, 20}, {4, 3}}, {{3, 14}}, {{4, 2}}, {}, {}};
    int start = 0;
    for(auto x:dijkstrasAlgorithm(start,edges))
        cout<<x<<" ";
    cout<<endl;
    return 0;
}