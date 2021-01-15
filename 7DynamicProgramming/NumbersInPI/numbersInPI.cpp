#include <bits/stdc++.h>
using namespace std;

int getMinSpaces(string pi, unordered_set<string> numbersTable, vector<int> &cache, int startIdx) {
    if(startIdx==pi.size())
        return -1;
    if(cache[startIdx]!=INT_MAX)
        return cache[startIdx];
    int minSpaces=INT_MAX;
    for(int idx=startIdx;idx<pi.size();idx++) {
        string prefix = pi.substr(startIdx,idx-startIdx+1);
        if(numbersTable.find(prefix)!=numbersTable.end()) {
            int minSpacesInSuffix=getMinSpaces(pi,numbersTable,cache,idx+1);
            if(minSpacesInSuffix==INT_MAX)
                minSpaces=min(minSpaces,minSpacesInSuffix);
            else
                minSpaces=min(minSpaces,minSpacesInSuffix+1);
        }
    }
    cache[startIdx]=minSpaces;
    return cache[startIdx];
}

int numbersInPi(string pi, vector<string> numbers) {
    unordered_set<string> numbersTable;
    for(auto x: numbers)
        numbersTable.insert(x);
    vector<int> cache(pi.size(),INT_MAX);
    int minSpaces = getMinSpaces(pi,numbersTable,cache,0);
    return minSpaces==INT_MAX?-1:minSpaces;
}

int main() {
    string PI = "3141592653589793238462643383279";
    vector<string> numbers = {"314159265358979323846", "26433", "8", "3279", "314159265","35897932384626433832",  "79"};
    cout<<(numbersInPi(PI, numbers) == 2);
    return 0;
}