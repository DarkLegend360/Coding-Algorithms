#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>>& grid, int row, int col) {
    return row>=0 && col>=0 && row<grid.size() && col<grid[0].size() && grid[row][col]==1;
}
void DFS(vector<vector<int>>& grid, int row, int col, string &s) {
    grid[row][col]=0;
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for(int i=0;i<directions.size();i++) {
        int xNext = row+directions[i][0];
        int yNext = col+directions[i][1];
        if(isSafe(grid, xNext, yNext)){
            s=s+to_string(i);
            DFS(grid, xNext, yNext, s);
        }
    }
}
int numberOfDistinctIslands(vector<vector<int>>& grid) {
    unordered_set<string> pattern;
    for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[0].size();j++)
            if(isSafe(grid, i, j)) {
                string s="a";
                DFS(grid, i, j, s);
                pattern.insert(s);
            }
    return pattern.size();
}
int main() {
    vector<vector<int>> grid = {
        {1,1,1,1,1},
        {1,0,0,0,0},
        {0,0,0,0,1},
        {1,1,0,0,1}
    };
    cout<<numberOfDistinctIslands(grid)<<endl;
    return 0;
}