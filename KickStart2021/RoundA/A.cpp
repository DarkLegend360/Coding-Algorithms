// K goodness string
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        string s;
        int n,k;
        cin>>n>>k;
        cin>>s;
        int goodness=0;
        for(int i=0;i<n/2;i++) {
            if(s[i]!=s[n-i-1])
                goodness++;
        }
        cout<<"Case #"<<i<<": "<<abs(k-goodness)<<"\n";
    }
    return 0;
}