
#include <bits/stdc++.h>
using namespace std;

void ClockWise(vector<vector<int>> &mat,int N) {
    reverse(mat.begin(),mat.end());
    for(int i=0;i<N;i++)
        for(int j=0;j<i;j++)
            swap(mat[i][j],mat[j][i]);
}
void AntiClockWise(vector<vector<int>> &mat,int N) {
    for(auto &x : mat)
        reverse(x.begin(),x.end());
    for(int i=0;i<N;i++)
        for(int j=0;j<i;j++)
            swap(mat[i][j],mat[j][i]);
}


int main() {
    int N=4;
    vector<vector<int>> mat= { 
        { 1, 2, 3, 4 }, 
        { 5, 6, 7, 8 }, 
        { 9, 10, 11, 12 }, 
        { 13, 14, 15, 16 } 
    };
    //ClockWise(mat,N);
    AntiClockWise(mat,N);
    for(auto x:mat) {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}