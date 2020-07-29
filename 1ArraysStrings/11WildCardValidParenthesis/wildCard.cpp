#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int Open=0,maxOpen=0;
    for(auto x:s) {
        if(x=='(') {
            Open++;
            maxOpen++;
        } else if(x==')') {
            Open--;
            maxOpen--;
        } else {
            Open--;
            maxOpen++;
        }
        if(maxOpen<0) {
            cout<<"Invalid"<<endl;
            return 0;
        }
        Open=max(Open,0);
    }
    if(Open==0)
        cout<<"Valid"<<endl;
    else
        cout<<"Invalid"<<endl;
    return 0;
}