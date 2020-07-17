#include <bits/stdc++.h>
using namespace std;

int getMinTime(vector<int> arr,int n,int curSum,int Total) {
    if(n==-1)
        return max(curSum,Total-curSum);
    return min(getMinTime(arr,n-1,curSum+arr[n],Total),getMinTime(arr,n-1,curSum,Total));
}


int main() {
    string n,inp;
    getline(cin,n);
    vector<int> arr;
    stringstream token(n);
    while(token) {
        token>>inp;
        arr.push_back(stoi(inp));
    }
    arr.pop_back();
    int sum= accumulate(arr.begin(),arr.end(),0);
    cout<<getMinTime(arr,arr.size()-1,0,sum)<<endl;
    return 0;
}