#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n,e;
    cin>>n;
    long long res = n*(n+1)/2;
    for(int i=0;i<n-1;i++) {
        cin>>e;
        res-=e;
    }
    cout<<res<<endl;
    return 0;
}