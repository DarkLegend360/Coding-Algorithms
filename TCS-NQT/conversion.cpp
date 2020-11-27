#include <bits/stdc++.h>
using namespace std;

int BinToDec(int n) {
    int res=0;
    int exp=0;
    while(n!=0) {
        res+=(n%10)*pow(2,exp++);
        n/=10;
    }
    return res;
}
long long int DecToBin(int n) {
    long long int res=0;
    int temp=1;
    while(n!=0) {
        res+=(n%2)*temp;
        n/=2;
        temp*=10;
    }
    return res;
}

int OctalToDec(int n) {
    int res=0;
    int exp=0;
    while(n!=0) {
        res+=(n%10)*pow(8,exp++);
        n/=10;
    }
    return res;
}
long long int DecToBin(int n) {
    long long int res=0;
    int temp=1;
    while(n!=0) {
        res+=(n%8)*temp;
        n/=8;
        temp*=10;
    }
    return res;
}

int main() {
    int n;
    cin>>n;
    //cout<<BinToDec(n);
    cout<<DecToBin(n);
    return 0;
}