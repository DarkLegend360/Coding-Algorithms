#include <bits/stdc++.h>

using namespace std;

void doMerge(vector<int> &arr,vector<int> &aux,int startIdx,int midIdx,int endIdx) {
    int i=startIdx;
    int j=midIdx+1;
    int k=startIdx;
    while(i<=midIdx && j<=endIdx) {
        if(aux[i]<=aux[j])
            arr[k++]=aux[i++];
        else
            arr[k++]=aux[j++];
    }
    while(i<=midIdx)
        arr[k++]=aux[i++];
    while(j<=endIdx)
        arr[k++]=aux[j++];
}

void mergeSortHelper(vector<int> &arr,vector<int> &aux,int startIdx,int endIdx) {
    if(startIdx>=endIdx)
        return;
    int midIdx=startIdx+(endIdx-startIdx)/2;
    mergeSortHelper(aux,arr,startIdx,midIdx);
    mergeSortHelper(aux,arr,midIdx+1,endIdx);
    doMerge(arr,aux,startIdx,midIdx,endIdx);
}

void mergeSort(vector<int> &arr) {
    vector<int> aux = arr;
    mergeSortHelper(arr,aux,0,arr.size()-1);
}

int main() {
    vector<int> arr = {8, 5, 2, 9, 5, 6, 3};
    mergeSort(arr);
    for(auto x:arr)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}