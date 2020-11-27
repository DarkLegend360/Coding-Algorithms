#include <bits/stdc++.h>
using namespace std;
#define MAX 130000
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<bool> prime(MAX+1,true);
    for(long long int i=2;i*i<=MAX;i++)
        if(prime[i])
            for(long long int j=i*i;j<=MAX;j+=i) 
                prime[j]=false;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> B(n,0);
        for(int i=0;i<n;i++)
            cin>>B[i];
        vector<int> A(n,0);
        long long int x=2;
        for(long long int i=0;i<n;i++) {
            while(!prime[x])
                x++;
            A[i]=x++;
        }
        for(long long int i=0;i<n;i++)
            if(i+1!=B[i])
                A[i]=A[B[i]-1];
        for(long long int i=0;i<n;i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }
    return 0;
}