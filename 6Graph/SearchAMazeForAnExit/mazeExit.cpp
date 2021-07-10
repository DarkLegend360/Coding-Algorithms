#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int row;
    int col;
    Node(int row, int col) {
        this->row=row;
        this->col=col;
    }
};

bool isSafe(vector<vector<int>> grid, int row, int col) {
    return row>=0 && col>=0 && row<grid.size() && col<grid[0].size() && grid[row][col]==1;
}
vector<Node> getNeighbours(vector<vector<int>> grid, Node curNode) {
    vector<Node> neighbours;
    vector<Node> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    for(auto direction : directions)
        if(isSafe(grid, curNode.row+direction.row, curNode.col+direction.col))
            neighbours.push_back(Node(curNode.row+direction.row, curNode.col+direction.col));
    return neighbours;
}

bool isValidPath(vector<vector<int>> grid, Node node, vector<vector<int>> &path, Node end) {
    path.push_back({node.row, node.col});
    grid[node.row][node.col]=0;
    if(node.row==end.row && node.col==end.col)
        return true;
    vector<Node> neighbours = getNeighbours(grid, node);
    for(auto neighbour : neighbours){
        if(isValidPath(grid, neighbour, path, end)) 
            return true;
        grid[node.row][node.col]=1;
        path.pop_back();
    }
    return false;
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 1, 1},
        {1, 1, 0, 0, 1}
    };
    Node start = Node(4,0);
    Node end = Node(0,4);
    stack<Node> myStack;
    myStack.push(start);
    vector<vector<int>> path;
    isValidPath(grid, start, path, end);
    for(auto x : path)
        cout<<x[0]<<" "<<x[1]<<endl;
    return 0;
}