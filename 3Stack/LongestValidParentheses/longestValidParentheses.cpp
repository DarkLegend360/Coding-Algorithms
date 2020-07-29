#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int res=0;
    stack<int> st;
    st.push(-1);
    for(int i=0;i<s.size();i++) {
        if(s[i]=='(') {
            st.push(i);
        } else {
            st.pop();
            if(st.empty())
                st.push(i);
            else
                res=max(res,i-st.top()); 
        }
    }
    cout<<"Result: "<<res<<endl;
    return 0;
}