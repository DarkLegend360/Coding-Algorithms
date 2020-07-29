#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    string open="{([";
    unordered_map<char,char> mp= {
        {'}','{'},
        {']','['},
        {')','('}
    };
    stack<char> st;
    for(auto x:s) {
        if(open.find(x)!=string::npos)
            st.push(x);
        else {
            if(st.empty() || st.top()!=mp[x]) {
                cout<<"Invalid"<<endl;
                return 0;
            }
            st.pop();
        }
    }
    if(st.empty()) cout<<"Valid"<<endl;
    else cout<<"Invalid"<<endl;
    return 0;
}