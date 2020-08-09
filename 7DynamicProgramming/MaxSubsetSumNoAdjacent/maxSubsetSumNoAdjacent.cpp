#include <bits/stdc++.h>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> arr) {
    if(arr.size()==0) return 0;
    if(arr.size()==1) return arr[0];
    arr[1]=max(arr[0],arr[1]);
    for(int i=2;i<arr.size();i++)
        arr[i]=max(arr[i-1],arr[i-2]+arr[i]);
    return arr[arr.size()-1];
}

int main() {
    vector<int> arr = {7,10,12,7,9,14};
    cout<<maxSubsetSumNoAdjacent(arr)<<endl;
    return 0;
}