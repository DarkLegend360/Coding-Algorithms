#include <bits/stdc++.h>
using namespace std;

//Method B
int longestBalancedSubstring(string str) {
  int maxLength=0;
	stack<int> st;
	st.push(-1);
	for(int i=0;i<str.size();i++) {
		if(str[i]=='(')
			st.push(i);
		else {
			st.pop();
			if(st.empty())
				st.push(i);
			else {
				maxLength=max(maxLength,i-st.top());
			}
		}
	}
  return maxLength;
}


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