#include <bits/stdc++.h>
using namespace std;

int isUnique(string inp) {
    int flag=0;
    for(int i=0;i<inp.size();i++) {
        int bit = inp[i]-'a';
        if((flag & (1<<bit)) != 0)
            return i;
        flag|=(1<<bit);
        cout<<flag<<endl;
    }
    return -1;
}

int main() {
    string inp;
    cin>>inp;
    cout<<inp;
    int res=isUnique(inp);
    if(res==-1)
        cout<<"Characters Of String is Unique"<<endl;
    else
        cout<<"String is not unique and first repeating character found at index "<<res<<endl;
    return 0;
}