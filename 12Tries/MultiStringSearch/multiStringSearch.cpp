#include <bits/stdc++.h>
using namespace std;

//Native Approach O(BNS) B-len(big)  N-no of small string  S=size of largest small string
bool isInBigStringHelper(string bigString, string smallString, int idx) {
    int leftIdxSmall=0;
    int rightIdxSmall=smallString.size()-1;
    int leftIdxBig=idx;
    int rightIdxBig=idx+smallString.size()-1;
    while(leftIdxSmall<rightIdxSmall)
        if(bigString[leftIdxBig]!=smallString[leftIdxSmall] || smallString[rightIdxSmall]!=bigString[rightIdxBig])
            return false;
        leftIdxSmall++;
        leftIdxBig++;
        rightIdxBig--;
        rightIdxSmall--;
    return true;
}

bool isInBigString(string bigString,string smallString) {
    for(int idx=0;idx<bigString.size();idx++) {
        if(idx+smallString.size()>bigString.size())
            break;
        if(isInBigStringHelper(bigString,smallString,idx))
            return true;
    }
    return false;
}

vector<bool> multiStringSearch(string bigString, vector<string> smallStrings) {
    vector<bool> results;
    for(auto smallString : smallStrings)
        results.push_back(isInBigString(bigString,smallString));
    return results;
}

int main() {
    vector<bool> expected{true, false, true, true, false, true, false};
    assert(multiStringSearch("this is a big string",{"this", "yo", "is", "a", "bigger", "string","kappa"}) == expected);
    return 0;
}