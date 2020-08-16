#include <bits/stdc++.h>
using namespace std;

vector<int> maxSumIncreasingSubsequence(vector<int> arr) {
    vector<int> sum = arr;
    vector<int> seq(arr.size(),INT_MIN);
    
}

int main() {
    vector<int> arr ={10, 70, 20, 30, 50, 11, 30};
    for(auto x:maxSumIncreasingSubsequence(arr))
        cout<<x<<" ";
    cout<<endl;
    return 0;
}