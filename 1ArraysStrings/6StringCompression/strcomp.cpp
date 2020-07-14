#include <bits/stdc++.h>
using namespace std;

string StringCompression(string s) {
    int idx=0;
    int i=0,j=0,n=s.size();
    while(i<n && j<n) {
        i=j;
        while(j<n && s[i]==s[j])
            j++;
        s[idx++]=s[i];
        if(j-i>1) {
            string count=to_string(j-i);
            for(auto x:count)
                s[idx++]=x;
        }
    }
    return s.substr(0,idx);
}

int main() {
    string s;
    cin>>s;
    cout<<StringCompression(s)<<endl;
    return 0;
}
