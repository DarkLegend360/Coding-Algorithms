#include <bits/stdc++.h>
using namespace std;

bool checkPathExistsHelper(vector<vector<int>> &graph, int from, int to, unordered_set<int> &visited){
    if(from==to)
        return true;
    if(visited.find(from)!=visited.end())
        return false;
    visited.insert(from);
    for(int neighbour : graph[from]) 
        if(checkPathExistsHelper(graph, neighbour, to, visited))
            return true;
    return false;
}
bool checkPathExists(vector<vector<int>> &graph, int from, int to){
    unordered_set<int> visited;
    return checkPathExistsHelper(graph, from, to, visited);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin>>N>>M;
    int x, y;
    vector<vector<int>> graph(N,vector<int>());
    for(int i=0;i<M;i++){
        cin>>x>>y;
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>x>>y;
        if(checkPathExists(graph, x-1, y-1))
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
    }
    return 0;
}
