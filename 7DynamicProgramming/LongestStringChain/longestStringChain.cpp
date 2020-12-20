#include <bits/stdc++.h>
using namespace std;

vector<string> longestStringChain(vector<string> strings) {
    int maxChainLength=0;
    string maxLengthString="";
    unordered_map<string,pair<string,int>> lookup;
    sort(strings.begin(),strings.end(),[](auto &a,auto &b){return a.size()<b.size();});
    for(auto s: strings)
        lookup[s]=make_pair("",1);
    for(auto s:strings) {
        for(int i=0;i<s.size();i++) {
            string match = s.substr(0,i)+s.substr(i+1);
            if(lookup.find(match)!=lookup.end() && lookup[s].second<lookup[match].second+1){
                lookup[s]=make_pair(match,lookup[match].second+1);
                if(lookup[match].second+1 > maxChainLength) {
                    maxLengthString=s;
                    maxChainLength=lookup[match].second+1;
                }
            }
        }
    }
    vector<string> results;
    string search = maxLengthString;
    while(search!="") {
        results.push_back(search);
        search=lookup[search].first;
    }
    if(results.size()==1) return {};
    return results;
}

int main() {
    vector<string> arr = {"abde", "abc", "abd", "abcde", "ade", "ae", "1abde", "abcdef"};
    for(auto x: longestStringChain(arr))
        cout<<x<<endl;
    return 0;
}