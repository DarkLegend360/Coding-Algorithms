#include <bits/stdc++.h>
using namespace std;
//int main() {
//      vector<int> denoms = {1, 5, 10};
//      int n=7;
//      vector<int> dp(n+1,INT_MAX);
//      dp[0]=0;
//      for(auto d:denoms) {
//          for(int c=1;c<=n;c++) {
//             if(c>=d)
//                 if(dp[c-d]==INT_MAX)
//                     dp[c]=min(dp[c],dp[c-d]);
//                 else
//                     dp[c]=min(dp[c],dp[c-d]+1);
//          }
//      }
//      cout<<(dp[n]==INT_MAX?-1:dp[n])<<endl;
//      return 0;
//}


int main() {
    vector<int> denoms = {1,2,4,6};
    int n=18;
    vector<vector<int>> dp(denoms.size()+1,vector<int>(n+1,INT_MAX));
    // for(int i=1;i<=n;i++)
    //     dp[0][i]=i;
    for(int i=0;i<=denoms.size();i++)
        dp[i][0]=0;
    for(int i=1;i<=denoms.size();i++) {
        int d=denoms[i-1];
        for(int j=1;j<=n;j++) {
            if(j>=d)
                dp[i][j]=min(dp[i][j-d]+1,dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    cout<<"Result: "<<dp[denoms.size()][n]<<endl;
    int i=denoms.size();
    int j=n;
    while(i>0 && j>0) {
        if(dp[i][j]==dp[i-1][j])
            i--;
        else {
            cout<<denoms[i-1]<<endl;
            j-=denoms[i-1];
        }
    }
}