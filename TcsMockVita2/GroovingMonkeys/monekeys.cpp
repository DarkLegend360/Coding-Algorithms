#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,res=0;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        vector<int> oldVals=arr;
        vector<int> newVals(n,0);
        while(newVals!=arr) {
            fill(newVals.begin(),newVals.end(),0);
            for(int i=0;i<n;i++)
                newVals[arr[i]-1]=oldVals[i];
            oldVals=newVals;
            res++;
        }
        cout<<res<<endl;
    }
    return 0;
}