// Checksum
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int x=1;x<=t;x++) {
        int n;
        cin>>n;
        vector<vector<int>> A(n,vector<int>(n,0)),B(n,vector<int>(n,0));
        vector<int> cR(n,0), cC(n,0);   
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>A[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>B[i][j];
        for(int i=0;i<n;i++)
            cin>>cR[i];
        for(int i=0;i<n;i++)
            cin>>cC[i];
        int minHours=0;

        
        cout<<"Case #"<<x<<": "<<minHours<<"\n";
    }
    return 0;
}