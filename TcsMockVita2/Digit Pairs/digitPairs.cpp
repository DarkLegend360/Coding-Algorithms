#include <bits/stdc++.h>
using namespace std;

int findLargest(string inp) {
    int res=0;
    int num = stoi(inp);
    while(num!=0) {
        if((num%10)>res)
            res=num%10;
        num/=10;
    }
    return res;
}

int findSmallest(string inp) {
    int res=INT_MAX;
    int num = stoi(inp);
    while(num!=0) {
        if((num%10)<res)
            res=num%10;
        num/=10;
    }
    return res;
}

int main() {
    int n;
    cin>>n;
    if(n==0) {
        cout<<0<<endl;
        return 0;
    }
    vector<string> arr(n+1);
    for(int i=1;i<=n;i++)
         cin>>arr[i];
    for(int i=1;i<=n;i++) {
        int a=findLargest(arr[i])*11;
        int b=findSmallest(arr[i])*7;
        string res=to_string(a+b);
        arr[i]=res.substr(res.size()-2);
    }
    unordered_map<int,vector<int>> Odd,Even;
    for(int i=1;i<=n;i++) {
        if(i%2==0)
            Even[arr[i][0]-'0'].push_back(i);
        else
            Odd[arr[i][0]-'0'].push_back(i);
    }
    int pairs=0;
    for(auto x:Even) {
        if(x.second.size()==2)
            pairs++;
        else if(x.second.size()>2)
            pairs+=2;
    }
    for(auto x:Odd) {
        if(x.second.size()==2)
            pairs++;
        else if(x.second.size()>2)
            pairs+=2;
    }
    cout<<pairs;
    return 0;
}