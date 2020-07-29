#include <bits/stdc++.h>
using namespace std;

void printPar(int open,int close,int N,string s) {
    if(close==N) {
        cout<<s<<endl;
        return;
    }
    if(open>close)
        printPar(open,close+1,N,s+"}");
    if(open<N)
        printPar(open+1,close,N,s+"{");
}

int main() {
    int n;
    cin>>n;
    printPar(0,0,n/2,"");
    return 0;
}