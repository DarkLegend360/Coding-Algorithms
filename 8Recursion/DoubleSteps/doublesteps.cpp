#include <bits/stdc++.h>
using namespace std;

int climblingSteps(int n,vector<int> &mem) {
    if(mem[n]==-1)
        mem[n]=climblingSteps(n-2,mem)+climblingSteps(n-1,mem);
    return mem[n];
}

int main() {
    int n;
    cin>>n;
    vector<int> mem(n+1,-1);
    mem[0]=1;
    mem[1]=1;
    cout<<climblingSteps(n,mem)<<endl;
    return 0;
}