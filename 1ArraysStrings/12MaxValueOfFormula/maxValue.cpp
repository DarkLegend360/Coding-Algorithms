#include <bits/stdc++.h>
using namespace std;

//max Value Of
// a[i]-a[j]+a[k]
// such that i<j<k


int main() {
    int n=5;
    vector<int> arr={4, 8, 9, 2, 20};
    vector<int> T1(n+1,INT_MIN),T2(n,INT_MIN),T3(n-1,INT_MIN),T4(n-2,INT_MIN);
    for(int i=n-1;i>=0;i--)
        T1[i]=max(T1[i+1],arr[i]);
    for(int i=n-2;i>=0;i--)
        T2[i]=max(T2[i+1],arr[i]+T1[i+1]);
    for(int i=n-3;i>=0;i--)
        T3[i]=max(T3[i+1],arr[i]+T2[i+1]);
    cout<<T3[0]<<endl;
    return 0;
}