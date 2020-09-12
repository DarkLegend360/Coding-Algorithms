#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,res=0;
    cin>>n;
    vector<long long> arr(n,0);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(i>0)
            if(arr[i]-arr[i-1]<0) {
                res+=arr[i-1]-arr[i];
                arr[i]+=arr[i-1]-arr[i];
            }
    }
    cout<<res<<endl;
    return 0;
}