#include <bits/stdc++.h>
using namespace std;

int main() {
    int D,P;
    cin>>D>>P;
    vector<bool> prime(D+1,true);
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i*i<=D;i++) 
        if(prime[i]==true) 
            for(int j=i*i;j<=D;j+=i)
                prime[j]=false; 
    int x=D/P;
    vector<vector<int>> arr(P,vector<int>(x,0));
    for(int i=0;i<P;i++){
        for(int j=0;j<x;j++) {
            arr[i][j]=prime[(x*i)+j]?1:0;
        }
    }
    int res=0;
    for(int i=P-2;i>=0;i--){
        for(int j=x-1;j>=0;j--) {
            if(arr[i+1][j]>0 && arr[i][j]!=0)
                arr[i][j]=1;
            else
                arr[i][j]=0;
        }
    }
    for(auto x:arr[0])
        if(x==1)
            res++;
    cout<<res;
}