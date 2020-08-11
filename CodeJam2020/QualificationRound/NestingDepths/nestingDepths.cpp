#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin>>T;
    for(int x=1;x<=T;x++) {
        string inp;
        cin>>inp;
        int open=0;
        string res="";
        for(char x:inp) {
            while(open<(x-'0')) {
                res+="(";
                open++;
            }
            while(open>(x-'0')) {
                res+=")";
                open--;
            }
            res+=x;
        }
        while(open>0) {
            res+=")";
            open--;
        }
        cout<<"Case #"<<x<<": "<<res<<endl;
    }
    return 0;
}