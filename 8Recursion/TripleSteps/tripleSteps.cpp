#include <bits/stdc++.h>
using namespace std;

int climbingSteps(int n,vector<int> &mem) {
    if(mem[n]==-1)
        mem[n]=climbingSteps(n-3,mem)+climbingSteps(n-2,mem)+climbingSteps(n-1,mem);
    return mem[n];
}

int main() {
    int n;
    cin>>n;
    vector<int> mem(n+1,-1);
    mem[0]=1;
    mem[1]=1;
    mem[2]=2;
    cout<<climbingSteps(n,mem)<<endl;
    return 0;
}