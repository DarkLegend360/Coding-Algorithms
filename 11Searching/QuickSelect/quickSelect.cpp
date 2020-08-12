#include <bits/stdc++.h>
using namespace std;

int quickSelect(vector<int> &arr,int startIdx,int endIdx,int K) {
    if(startIdx>endIdx) return -1;
    int pivotIdx=startIdx;
    int leftIdx=startIdx+1;
    int rightIdx=endIdx;
    while(leftIdx<=rightIdx) {
        if(arr[leftIdx]>arr[pivotIdx] && arr[pivotIdx]>arr[rightIdx])
            swap(arr[leftIdx],arr[rightIdx]);
        if(arr[leftIdx]<=arr[pivotIdx])
            leftIdx++;
        if(arr[rightIdx]>=arr[pivotIdx])
            rightIdx--;
    }
    swap(arr[rightIdx],arr[pivotIdx]);
    if(rightIdx==K)
        return arr[rightIdx];
    if(rightIdx>K)
        return quickSelect(arr,startIdx,rightIdx-1,K);
    else
        return quickSelect(arr,rightIdx+1,endIdx,K);
}

int main() {
    int K=3;
    vector<int> arr = {8, 5, 2, 9, 7, 6, 3};
    cout<<quickSelect(arr,0,arr.size()-1,K-1)<<endl;
    return 0;
}