#include <bits/stdc++.h>
using namespace std;

vector<int> smallestDifference(vector<int> arr1, vector<int> arr2) {
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    vector<int> res(2,0);
    int idx1=0,idx2=0;
    int minDiff=INT_MAX;
    int diff=abs(arr1[idx1]-arr2[idx2]);
    while(idx1<arr1.size() && idx2<arr2.size()) {
        if(arr1[idx1]<arr2[idx2])
            idx1++;
        else if(arr1[idx1]>arr2[idx2])
            idx2++;
        else
            return {arr1[idx1],arr2[idx2]};
        if(diff>abs(arr1[idx1]-arr2[idx2])) {
            res[0]=arr1[idx1];
            res[1]=arr2[idx2];
            diff=abs(arr1[idx1]-arr2[idx2]);
        }
    }
    return res;
}

int main() {
    vector<int> arr1={-1, 5, 10, 20, 28, 3};
    vector<int> arr2={26, 134, 20, 15, 17};
    for(auto x:smallestDifference(arr1,arr2))
        cout<<x<<" ";
    cout<<endl;
    return 0;
}

