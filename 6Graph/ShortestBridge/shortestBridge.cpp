#include <bits/stdc++.h>
using namespace std;

/*
    1.Node with value 1
    2.Find all adjacent 1's (Now we have one island)
    3.While doing step 2 make a copy of all border nodes of island 1
    4.Perform BFS on all the stored border nodes
*/

class Node {
    public:
    int row;
    int col;
    Node(int row, int col) {
        this->row=row;
        this->col=col;
    }
};

string stringify(Node node) {
    return to_string(node.row)+"H"+to_string(node.col);
}

bool isSafe(vector<vector<int>>& grid, Node node) {
    return node.row>=0 && node.col>=0 && node.row<grid.size() && node.col<grid[0].size() && grid[node.row][node.col]!=-1;
}

void discoverIsland(vector<vector<int>>& grid, Node node, queue<Node> &myQueue) {
    if(!isSafe(grid, node))
        return;
    if(grid[node.row][node.col]!=1)
        return;
    grid[node.row][node.col]=-1;
    myQueue.push(node);
    vector<vector<int>> directions={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for(auto direction : directions) {
        Node nextNode= Node(node.row+direction[0], node.col+direction[1]);
        if(isSafe(grid, nextNode))
            discoverIsland(grid, nextNode, myQueue);
    }
}

int shortestBridge(vector<vector<int>>& grid) {
    queue<Node> myQueue;
    unordered_map<string,Node> border;
    int flag=true;
    for(int i=0;i<grid.size()&&flag;i++)
        for(int j=0;j<grid[0].size()&&flag;j++) 
            if(grid[i][j]==1) {
                discoverIsland(grid, Node(i, j), myQueue);
                flag=false;
            }

    int distance=0;
    while(!myQueue.empty()) {
        int size=myQueue.size();
        for(int i=0;i<size;i++) {
            Node currentNode = myQueue.front();
            myQueue.pop();
            vector<vector<int>> directions={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            for(auto direction : directions) {
                Node nextNode = Node(currentNode.row+direction[0], currentNode.col+direction[1]);
                if(isSafe(grid, nextNode)) {
                    if(grid[nextNode.row][nextNode.col]==1 )
                        return distance;
                    myQueue.push(nextNode);
                    grid[nextNode.row][nextNode.col]=-1;
                }
            }
        }
        distance++;
    }
    return -1;
}

int main() {
    // vector<vector<int>> grid = {
    //     {0,1,0},
    //     {0,0,0},
    //     {0,0,1}
    // };
    vector<vector<int>> grid = {
        {1,1,1,1,1},
        {1,0,0,0,1},
        {1,0,1,0,1},
        {1,0,0,0,1},
        {1,1,1,1,1}
    };
    cout<<shortestBridge(grid)<<endl;
    return 0;
}