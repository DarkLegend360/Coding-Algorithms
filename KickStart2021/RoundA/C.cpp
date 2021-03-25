//Rabbit House
#include <bits/stdc++.h>
using namespace std;

class GridInfo {
    public:
    long long int x;
    long long int y;
    long long int value;
    GridInfo(long long int x, long long int y, long long int value) {
        this->x=x;
        this->y=y;
        this->value=value;
    }
};

struct compare {
    bool operator()(GridInfo const &a, GridInfo const &b) {
        return a.value < b.value;
    }
};

int main() {
    long long int t;
    cin>>t;
    for(long long int x=1;x<=t;x++) {
        long long int R,C;
        cin>>R>>C;
        vector<vector<long long int>> grid(R,vector<long long int>(C,0));
        priority_queue<GridInfo, vector<GridInfo>, compare> maxGrid;
        for(long long int i=0;i<R;i++)
            for(long long int j=0;j<C;j++){
                cin>>grid[i][j];
                maxGrid.push(GridInfo(i, j, grid[i][j]));
        }
        long long int score=0;
        while(!maxGrid.empty()) {
            GridInfo currentElement = maxGrid.top();
            long long int curX=currentElement.x;
            long long int curY=currentElement.y;
            long long int curValue = currentElement.value;
            maxGrid.pop();
            if(curValue==grid[curX][curY]) {
                if(curX-1>=0){
                    long long int absValue = abs(grid[curX][curY] - grid[curX-1][curY]);
                    if(absValue>1) {
                        grid[curX-1][curY]+=absValue-1;
                        maxGrid.push(GridInfo(curX-1, curY, grid[curX-1][curY]));
                        score+=(absValue-1);
                    }
                    
                }
                if(curY-1>=0){
                    long long int absValue = abs(grid[curX][curY] - grid[curX][curY-1]);
                    if(absValue>1) {
                        grid[curX][curY-1]+=absValue-1;
                        maxGrid.push(GridInfo(curX, curY-1, grid[curX][curY-1]));
                        score+=(absValue-1);
                    }
                }
                if(curX+1<R){
                    long long int absValue = abs(grid[curX][curY] - grid[curX+1][curY]);
                    if(absValue>1) {
                        grid[curX+1][curY]+=absValue-1;
                        maxGrid.push(GridInfo(curX+1, curY, grid[curX+1][curY]));
                        score+=(absValue-1);
                    }
                }
                if(curY+1<C){
                    long long int absValue = abs(grid[curX][curY] - grid[curX][curY+1]);
                    if(absValue>1) {
                        grid[curX][curY+1]+=absValue-1;
                        maxGrid.push(GridInfo(curX, curY+1, grid[curX][curY+1]));
                        score+=(absValue-1);
                    }
                }
            }
        }
        cout<<"Case #"<<x<<": "<<score<<"\n";
    }
    return 0;
}