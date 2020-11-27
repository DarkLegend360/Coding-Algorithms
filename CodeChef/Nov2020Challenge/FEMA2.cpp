#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        long long int n,k,r,res=0;
        cin>>n>>k;
        string st;
        cin>>st;
        long long int i=0,j=0,sheet=0;
        while(i<n && j<n) {
            if(st[i]=='M') {
                if(st[j]=='I') {
                    sheet=0;
                    for(long long int x=min(i,j);x<max(i,j);x++) {
                        if(st[x]==':')
                            sheet++;
                        else if(st[x]=='X') {
                            i=x;
                            j=x;
                            break;
                        }
                    }
                    if(st[i]=='X' && st[j]=='X')
                        continue;
                    long long int p = k+1-abs(j-i)-sheet;
                    if(p>0) {
                        res++;
                        i++;
                        j++;
                    } else {
                        if(j>i)
                            i++;
                        else
                            j++;
                    }
                } else
                    j++;
            } else
                i++;
        }
        cout<<res<<endl;
    }
    return 0;
}