#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> matrix, int row, int col) {
    return row<matrix.size() && col<matrix[0].size() && row>=0 && col>=0;
}

void depthFirstSearch(vector<vector<int>> &matrix, int row, int col) {
    if(!isSafe(matrix,row,col) || matrix[row][col]!=1)
        return;
    matrix[row][col]=2;
    depthFirstSearch(matrix,row,col+1);
    depthFirstSearch(matrix,row,col-1);
    depthFirstSearch(matrix,row+1,col);
    depthFirstSearch(matrix,row-1,col);
}

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
    int rowSize=matrix.size();
    int colSize=matrix[0].size();
    for(int row=0;row<rowSize;row++) {
        depthFirstSearch(matrix,row,0);
        depthFirstSearch(matrix,row,colSize-1);
    }
    for(int col=0;col<colSize;col++) {
        depthFirstSearch(matrix,0,col);
        depthFirstSearch(matrix,rowSize-1,col);
    }
    for(int row=0;row<rowSize;row++) {
        for(int col=0;col<colSize;col++) {
            if(matrix[row][col]==2)
                matrix[row][col]=1;
            else if(matrix[row][col]==1)
                matrix[row][col]=0;
        }
    }
    return matrix;
}


int main() {
    vector<vector<int>> input = {
        {1, 0, 0, 0, 0, 0}, 
        {0, 1, 0, 1, 1, 1}, 
        {0, 0, 1, 0, 1, 0},
        {1, 1, 0, 0, 1, 0}, 
        {1, 0, 1, 1, 0, 0}, 
        {1, 0, 0, 0, 0, 1},
    };
    vector<vector<int>> expected = {
        {1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 1, 1, 1}, 
        {0, 0, 0, 0, 1, 0},
        {1, 1, 0, 0, 1, 0}, 
        {1, 0, 0, 0, 0, 0}, 
        {1, 0, 0, 0, 0, 1},
    };
    auto actual = removeIslands(input);
    cout<<(expected == actual)<<endl;
    return 0;
}