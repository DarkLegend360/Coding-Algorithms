#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int> &arr,int startIdx,int endIdx) {
    if(startIdx>=endIdx) return;
    int pivIdx=startIdx;
    int leftIdx=startIdx+1;
    int rightIdx=endIdx;
    while(leftIdx <= rightIdx) {
        if(arr[leftIdx]> arr[pivIdx] && arr[rightIdx] < arr[pivIdx])
            swap(arr[leftIdx],arr[rightIdx]);
        if(arr[leftIdx]<=arr[pivIdx])
            leftIdx++;
        if(arr[rightIdx]>= arr[pivIdx])
            rightIdx--;
    }
    swap(arr[pivIdx],arr[rightIdx]);
    quickSort(arr,startIdx,rightIdx-1);
    quickSort(arr,rightIdx+1,endIdx);
    //Find Smaller side and perform it first (idk xD)
}

int main() {
    vector<int> arr={5,7,3,2,76,9,0,1,6,13,34,21};
    quickSort(arr,0,arr.size()-1);
    for(auto x:arr)
        cout<<x<<" ";
    cout<<endl;
}