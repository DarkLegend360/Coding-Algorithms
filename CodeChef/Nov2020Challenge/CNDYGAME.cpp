#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int q;
        cin>>q;
        vector<int> qry(q,0);
        for(int i=0;i<q;i++)
            cin>>qry[i];
    }
    return 0;
}