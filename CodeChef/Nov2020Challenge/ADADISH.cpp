#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n;
    cin>>t;
    while(t--) {
        int A=0,B=0;
        int time=0;
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr.begin(),arr.end(),greater<int>());
        A=arr[0];
        B=arr[1];
        for(int i=2;i<n;i++) {
            int mn=min(A,B);
            A-=mn;
            B-=mn;
            time+=mn;
            if(A==0)
                A=arr[i];
            else if(B==0)
                B=arr[i];
        }
        cout<<time+max(A,B)<<endl;
    }
    return 0;
}