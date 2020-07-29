#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> graph,int src) {
    int V=graph.size();
    vector<int> dist(V,INT_MAX);
    //vector<int> path(V,INT_MAX);
    //path[src]=src;
    dist[src]=0;
    vector<bool> visited(V,false);
    for(int x=0;x<V-1;x++) {
        int mn = INT_MAX,N;
        for(int i=0;i<V;i++) {
            if(!visited[i] && mn>dist[i]){
                mn=dist[i];
                N=i;
            }
        }
        visited[N]=true;

        for(int i=0;i<V;i++) {
            if(!visited[i] && graph[N][i] && dist[N]!=INT_MAX && dist[i]>dist[N]+graph[N][i]) {
                dist[i]=dist[N]+graph[N][i];
                //path[N]=i;
            }
                
        }
    }
    for(int i=0;i<V;i++)
        cout<<i<<" "<<dist[i]<<endl;
}


int main() {
    vector<vector<int>> graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    solve(graph, 0); 
    return 0;
}