#include <bits/stdc++.h>
using namespace std;

int getFirstDuplicateValue(vector<int> arr) {
    for(int i=0;i<arr.size();i++) {
        int idx=abs(arr[i])-1;
        if(arr[idx]<0)
            return abs(arr[i]);
        arr[idx]*=-1;
    }
    return -1;
}

int main() {
    vector<int> arr = {2, 1, 5, 2, 3, 3, 4};
    cout<<getFirstDuplicateValue(arr)<<endl;
    return 0;
}