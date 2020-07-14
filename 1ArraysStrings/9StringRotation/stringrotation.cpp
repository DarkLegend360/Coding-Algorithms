#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1="abcde";
    string s2="deabc";
    if(s1.size()==s2.size() && (s1+s1).find(s2)!=string::npos)
        cout<<"Valid"<<endl;
    else
        cout<<"Invalid"<<endl;
    return 0;
}