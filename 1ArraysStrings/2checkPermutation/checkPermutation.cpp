#include <bits/stdc++.h>
using namespace std;

bool checkPermutation(string s1,string s2) {
    if(s1.size()!=s2.size())
        return false;
    vector<int> flag(128,0);
    for(auto x:s1)
        flag[x]++;
    for(auto x:s2)
        flag[x]--;
    for(auto x:flag)
        if(x!=0)
            return false;
    return true;
}

int main() {
    string s1,s2;
    cin>>s1>>s2;
    if(checkPermutation(s1,s2))
        cout<<"The Given String Are Permutations"<<endl;
    else
        cout<<"They Are Not Permutations"<<endl;
    return 0;
}