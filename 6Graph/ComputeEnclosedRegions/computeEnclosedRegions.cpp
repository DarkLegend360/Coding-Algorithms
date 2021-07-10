#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int col) {
    return row>=0 && col>=0 && row<board.size() && col<board[0].size() && board[row][col]=='O';
}

vector<vector<int>> getNeighbours(vector<vector<char>>& board, int row, int col) {
    vector<vector<int>> neighbours;
    vector<vector<int>> directions= {{1, 0},{0, 1},{-1, 0},{0, -1}};
    for(auto direction : directions)
        if(isSafe(board, row+direction[0], col+direction[1]))
            neighbours.push_back({row+direction[0], col+direction[1]});
    return neighbours;
}

void DFS(vector<vector<char>>& board, int row, int col) {
    board[row][col]='Z';
    auto neighbours = getNeighbours(board, row, col);
    for(auto neighbour : neighbours)
        DFS(board, neighbour[0], neighbour[1]);
}

vector<vector<char>> computeEnclosedRegions(vector<vector<char>>& board) {
    for(int i=0;i<board.size();i++) {
        if(board[i][0]=='O')
            DFS(board, i, 0);
        if(board[i][board[0].size()-1]=='O')
            DFS(board, i, board[0].size()-1);
    }
    for(int i=0;i<board[0].size();i++) {
        if(board[0][i]=='O')
            DFS(board, 0, i);
        if(board[board.size()-1][i]=='O')
            DFS(board, board.size()-1, i);
    }
    for(int i=0;i<board.size();i++)
        for(int j=0;j<board[0].size();j++)
            if(board[i][j]=='Z')
                board[i][j]='O';
            else if(board[i][j]=='O')
                board[i][j]='X';
    return board;
}

int main() {
    vector<vector<char>> grid = {
        {'X', 'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'X', 'X'},
        {'X', 'X', 'X', 'O', 'X'},
        {'X', 'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'X', 'X'}
    };
    for(auto x : computeEnclosedRegions(grid)) {
        for(auto y : x)
            cout<<y<<" ";
        cout<<"\n";
    }

    return 0;
}