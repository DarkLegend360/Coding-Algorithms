#include <bits/stdc++.h>
using namespace std;

bool helper(string one, string two, string three, int oneIdx, int twoIdx) {
    int threeIdx=oneIdx+twoIdx;
    if(three.size()==threeIdx)
        return true;
    if(oneIdx<one.size() && one[oneIdx]==three[threeIdx])
        if(helper(one, two, three, oneIdx+1, twoIdx))
            return true;
    if(twoIdx<two.size() && two[twoIdx]==three[threeIdx])
        if(helper(one, two, three, oneIdx, twoIdx+1))
            return true;
    return false;
}
bool interweavingStrings(string one, string two, string three) {
    if((one.size()+two.size())!=three.size())
        return false;
    return helper(one, two, three, 0, 0);
}

/////////////////With Caching///////////////////////
bool helperX(string one, string two, string three, int oneIdx, int twoIdx, vector<vector<int>> &cache) {
    if(cache[oneIdx][twoIdx]!=-1)
        return cache[oneIdx][twoIdx];
    int threeIdx=oneIdx+twoIdx;
    if(threeIdx==three.size())
        return true;
    if(oneIdx<one.size() && one[oneIdx]==three[threeIdx]) {
        cache[oneIdx][twoIdx]=helperX(one, two, three, oneIdx+1, twoIdx, cache);
        if(cache[oneIdx][twoIdx]==true)
            return true;
    }
    if(twoIdx<two.size() && two[twoIdx]==three[threeIdx]) {
        cache[oneIdx][twoIdx]=helperX(one, two, three, oneIdx, twoIdx+1, cache);
        return cache[oneIdx][twoIdx];
    }
    cache[oneIdx][twoIdx]=false;
    return false;
}

bool interweavingStrings(string one, string two, string three) {
    if((one.size()+two.size())!=three.size())
        return false;
    vector<vector<int>> cache(one.size()+1, vector<int>(two.size()+1,-1));
    return helperX(one, two, three, 0, 0, cache);
}


int main() {
    string one = "algoexpert";
    string two = "your-dream-job";
    string three = "your-algodream-expertjob";
    cout<<interweavingStrings(one, two, three)<<endl;
    return 0;
}