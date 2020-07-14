#include <bits/stdc++.h>
using namespace std;

int main() {
    string s="Mr John Smith    ";
    int TrueLength=13;
    //getline(cin,s);
    int count=0;
    for(int i=0;i<TrueLength;i++)
        if(s[i]==' ')
            count++;
    s[TrueLength]='\0';
    int j=TrueLength+(count*2)-1;
    for(int i=TrueLength-1;i>=0;i--) {
        if(s[i]==' ') {
            s[j]='0';
            s[j-1]='2';
            s[j-2]='%';
            j-=3;
        } else
            s[j--]=s[i];
    }
    cout<<s<<endl;
    return 0;
}


/*
Easy Solution using String Manipulation
    for(int i=0;i<s.size();i++)
        if(s[i]==' ')
            s=s.substr(0,i)+"%20"+s.substr(i+1);
*/