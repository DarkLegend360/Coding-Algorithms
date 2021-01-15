#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> arr,int idx,int &result) {
    if(idx==arr.size()) {
        result++;
        return;
    }
    for(int i=idx;i<arr.size();i++) {
        if(arr[i]%(idx+1)==0 || (idx+1)%arr[i]==0) {
            swap(arr[idx],arr[i]);
            helper(arr,idx+1,result);
            swap(arr[idx],arr[i]);
        }
    }
}
int countArrangement(int n) {
    int result=0;
    vector<int> arr;
    for(int i=1;i<=n;i++)
        arr.push_back(i);
    helper(arr,0,result);
    return result;
}

int main() {

    return 0;
}