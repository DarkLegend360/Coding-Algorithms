#include <bits/stdc++.h>
using namespace std;

int main() {
    int n=3,m=3;
    vector<vector<int>> arr={
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    int Col0=1;
    for(int i=0;i<n;i++) {
        if(arr[i][0]==0) 
            Col0=0;
        for(int j=1;j<m;j++) {
            if(arr[i][j]==0) {
                arr[i][0]=0;
                arr[0][j]=0;
            }
        }
    }
    for(int i=n-1;i>=0;i--) {
        for(int j=m-1;j>=1;j--) {
            if(arr[i][0]==0||arr[0][j]==0)
                arr[i][j]=0;
        }
        if(Col0==0)
            arr[i][0]=0;
    }
    for(auto x:arr) {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}