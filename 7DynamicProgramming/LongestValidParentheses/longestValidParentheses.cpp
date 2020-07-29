#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int res=0;
    vector<int> dp(s.size()+1,0);
    for(int i=1;i<s.size();i++) {
        if(s[i]==')') {
            int srt=i-dp[i]-1;
            if(srt>=0 && s[srt]=='(') {
                dp[i+1]=dp[i]+dp[srt]+2;
                res=max(res,dp[i+1]);
            }     
        }
    }
    cout<<"Result: "<<res<<endl;
    return 0;
}