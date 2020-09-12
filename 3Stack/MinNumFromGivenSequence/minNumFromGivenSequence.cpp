#include <bits/stdc++.h>
using namespace std;

void getNums(string s) {
    string res="";
    stack<int> st;
    for(int i=0;i<=s.size();i++) {
        st.push(i+1);
        while(!st.empty() && (s[i]=='I'||i==s.size())) {
            res+=to_string(st.top())+" ";
            st.pop();
        }
    }
    cout<<res<<endl;
}

int main() {
    // string inp;
    // cin>>inp;
    getNums("IDID"); 
    getNums("I"); 
    getNums("DD"); 
    getNums("II"); 
    getNums("DIDI"); 
    getNums("IIDDD"); 
    getNums("DDIDDIID"); 
    return 0;
}