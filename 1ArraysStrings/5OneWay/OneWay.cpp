#include <bits/stdc++.h>
using namespace std;

bool OneWay(string s1,string s2) {
    int n=s1.size(),m=s2.size();
    if(abs(n-m)>1) return false;
    int i=0,j=0;
    bool flag=false;
    while(i<n && j<m) {
        if(s1[i]!=s2[j]) {
            if(flag) return false;
            flag=true;
            if(n==m) 
                i++;
        } else
            i++;
        j++;
    }
    return true;
}

int main() {
    string s1,s2;
    cin>>s1>>s2;
    if(s1.size()<s2.size()?OneWay(s1,s2):OneWay(s2,s1))
        cout<<"Valid"<<endl;
    else
        cout<<"Invalid"<<endl;
    return 0;
}