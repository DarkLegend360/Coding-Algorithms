#include <bits/stdc++.h>
using namespace std;

class Cell {
    public:
    int x,y,d;
    Cell(int a,int b,int c) {
        x=a,y=b,d=c;
    }
};

bool isSafe(int x,int y,int N,vector<vector<bool>> visited) {
    if(x>=0 && y>=0 && x<N && y<N && !visited[x][y]) return true;
    return false;
}

void solveKnight(int src[],int dest[],int N) {
    int dx[]={1,1,-1,-1,2,2,-2,-2};
    int dy[]={2,-2,2,-2,1,-1,1,-1};
    queue<Cell> q;
    vector<vector<bool>> visited(N,vector<bool>(N,false));
    q.push(Cell(src[0],src[1],0));
    while(!q.empty()) {
        Cell cur = q.front();
        q.pop();
        if(cur.x==dest[0] &&cur.y==dest[1]) {
            cout<<"Result: "<<cur.d<<endl;
            return;
        }
        for(int i=0;i<8;i++) {
            int x=cur.x+dx[i];
            int y=cur.y+dy[i];
            if(isSafe(x,y,N,visited)) {
                visited[x][y]=true;
                q.push(Cell(x,y,cur.d+1));
            }
        }
    }
}

int main() {
    int n=8;
    int src[]={0,0};
    int dest[]={0,1};
    solveKnight(src,dest,n);
    return 0;
}