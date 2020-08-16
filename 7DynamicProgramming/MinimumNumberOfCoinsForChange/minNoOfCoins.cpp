#include <bits/stdc++.h>
using namespace std;
 int main() {
     vector<int> denoms = {1, 5, 10};
     int n=7;
     vector<int> dp(n+1,INT_MAX);
     dp[0]=0;
     for(auto d:denoms) {
         for(int c=1;c<=n;c++) {
            if(c>=d)
                if(dp[c-d]==INT_MAX)
                    dp[c]=min(dp[c],dp[c-d]);
                else
                    dp[c]=min(dp[c],dp[c-d]+1);
         }
     }
     cout<<(dp[n]==INT_MAX?-1:dp[n])<<endl;
     return 0;
 }