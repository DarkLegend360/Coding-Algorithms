#include <bits/stdc++.h>
using namespace std;

vector<int> buildPattern(string substr) {
    vector<int> pattern(substr.size(),-1);
    int i=1;
    int j=0;
    while(i<substr.size()) {
        if(substr[i]==substr[j])
            pattern[i++]=j++;
        else if(j>0) 
            j=pattern[j-1]+1;
        else
            i++;
    }
    for(auto x:pattern)
        cout<<x<<" ";
    cout<<endl;
    return pattern;
}

bool checkMatch(string str,string substr,vector<int> pattern) {
    int i=0;
    int j=0;
    while(j<substr.size() && i<str.size()) {
        if(str[i]==substr[j]) {
            i++;
            j++;
        } else if(j>0)
            j=pattern[j-1]+1;
        else
            i++;
    }
    return j==substr.size();
}

bool knuthMorrisPrattAlgorithm(string str, string substr) {
    vector<int> pattern = buildPattern(substr);
    return checkMatch(str,substr,pattern);
}

int main() {
    string mainString = "aefoaefcdaefcdaed";
    string pattern = "aefcdaed";
    cout<<knuthMorrisPrattAlgorithm(mainString,pattern)<<endl;
}