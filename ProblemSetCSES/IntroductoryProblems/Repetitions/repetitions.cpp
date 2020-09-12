#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    long long res=1,i=0,c=1;
    while(i<s.size()-1) {
        if(s[i]!=s[i+1]) {
            res=max(res,c);
            c=1;
        } else
            c++;
        i++;
    }
    res=max(res,c);
    cout<<res<<endl;
    return 0;
}