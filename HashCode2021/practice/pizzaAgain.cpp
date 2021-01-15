#include <bits/stdc++.h>
using namespace std;

int main() {
    int M,two,three,four;
    cin>>M>>two>>three>>four;
    vector<vector<string>> item;
    int maxN=0;
    for(int i=0;i<M;i++) {
        int n;
        string s;
        cin>>n;
        maxN=max(n,maxN);
        vector<string> temp;
        for(int j=0;j<n;j++){
            cin>>s;
            temp.push_back(s);
        }
        item.push_back(temp);    
    }
    for(auto &x : item)
        sort(x.begin(),x.end());
    vector<vector<int>> common(M,vector<int>(M,0));
    return 0;
}