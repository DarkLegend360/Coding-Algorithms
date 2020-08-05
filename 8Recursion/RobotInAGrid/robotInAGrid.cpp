#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &maze,int r,int c) {
    if(r<0 || c<0 || r>=maze.size() || c>=maze[0].size() || maze[r][c]==1)
        return false;
    return true;
}

bool getPath(vector<vector<int>> &maze,int r,int c,vector<pair<int,int>> &path) {
    if(isSafe(maze,r,c)) {
        if((r==0 && c==0) || getPath(maze,r-1,c,path)) {
            path.push_back(make_pair(r,c));
            return true;
        }
        if(getPath(maze,r,c-1,path)) {
            path.push_back(make_pair(r,c));
            return true;
        }
            
    }
    return false;
}

int main() {
    vector<vector<int>> maze ={
        {0,0,1,0,0},
        {0,0,1,0,0},
        {0,0,1,0,0},
        {0,1,0,0,0},
        {0,0,0,0,0}
    };
    vector<pair<int,int>> path;
    int r,c;
    cin>>r>>c;
    getPath(maze,r,c,path);
    for(auto x:path)
        cout<<"("<<x.first<<","<<x.second<<")->";
    cout<<endl;
}