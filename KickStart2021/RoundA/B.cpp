//L Shaped Plots
#include <bits/stdc++.h>
using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int main() {
    int t;
    cin>>t;
    for(int x=1;x<=t;x++) {
        int R,C;
        cin>>R>>C;
        vector<vector<int>> grid(R,vector<int>(C,0));
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                cin>>grid[i][j];
        
        vector<vector<vector<int>>> gridInfo(R,vector<vector<int>>(C,vector<int>(4,0)));
        //Initial
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                if(grid[i][j]==1)
                    gridInfo[i][j]={1,1,1,1};

        //Grid
        for(int i=R-1;i>=0;i--) {
            for(int j=C-1;j>=0;j--) {
                if(grid[i][j]==1) {
                    if(i+1<R)
                        gridInfo[i][j][DOWN]=gridInfo[i+1][j][DOWN]+1;
                    if(j+1<C)
                        gridInfo[i][j][RIGHT]=gridInfo[i][j+1][RIGHT]+1;
                }
            }
        }
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                if(grid[i][j]==1) {
                    if(i-1>=0)
                        gridInfo[i][j][UP]=gridInfo[i-1][j][UP]+1;
                    if(j-1>=0)
                        gridInfo[i][j][LEFT]=gridInfo[i][j-1][LEFT]+1;
                }
            }
        }
        int score=0;
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                for(int k=2;k<=gridInfo[i][j][UP];k++) 
                    if(gridInfo[i][j][LEFT]>=k*2)
                        score++;
                for(int k=2;k<=gridInfo[i][j][UP];k++) 
                    if(gridInfo[i][j][RIGHT]>=k*2)
                        score++;
                for(int k=2;k<=gridInfo[i][j][DOWN];k++) 
                    if(gridInfo[i][j][LEFT]>=k*2)
                        score++;
                for(int k=2;k<=gridInfo[i][j][DOWN];k++) 
                    if(gridInfo[i][j][RIGHT]>=k*2)
                        score++;
                for(int k=2;k<=gridInfo[i][j][LEFT];k++) 
                    if(gridInfo[i][j][UP]>=k*2)
                        score++;
                for(int k=2;k<=gridInfo[i][j][LEFT];k++) 
                    if(gridInfo[i][j][DOWN]>=k*2)
                        score++;
                for(int k=2;k<=gridInfo[i][j][RIGHT];k++)
                    if(gridInfo[i][j][UP]>=k*2)
                        score++;
                for(int k=2;k<=gridInfo[i][j][RIGHT];k++)
                    if(gridInfo[i][j][DOWN]>=k*2)
                        score++;
            }
        }
        cout<<"Case #"<<x<<": "<<score<<"\n";
    }
    return 0;
}