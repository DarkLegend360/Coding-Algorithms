//Each Items can only be added once.
// 0/1 Knapsack

#include <bits/stdc++.h>
using namespace std;

void knapSack(vector<vector<int>> arr,int c) {
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int>(c+1,0));
    for(int i=1;i<=n;i++) {
        int curValue = arr[i-1][0];
        int curWeight = arr[i-1][1];
        for(int j=1;j<=c;j++) {
            if(curWeight>j)
                dp[i][j]=dp[i-1][j];
            else 
                dp[i][j]=max(dp[i-1][j-curWeight]+curValue,dp[i-1][j]);
        }
    }
    //Finding Sequence
    int i=n;
    int j=c;
    vector<int> seq;
    while(i>0 && j>0) {
        if(dp[i][j]==dp[i-1][j])
            i--;
        else{
            seq.insert(seq.begin(),arr[i-1][0]);
            j-=arr[i-1][1];
        }
    }
    for(auto x:seq)
        cout<<x<<" ";
    cout<<endl<<"Value: "<<dp[n][c]<<endl;
}

int main() {
    int cap=10;
    vector<vector<int>> arr = {{1, 2}, {4, 3}, {5, 6}, {6, 7}};
    knapSack(arr,cap);
    return 0;
}