#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr) {
    for(int i=0;i<arr.size()-1;i++)
        for(int j=0;j<arr.size()-1-i;j++)
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
}

void selectionSort(vector<int> &arr) {
    for(int i=0;i<arr.size()-1;i++) {
        int minIdx=i;
        for(int j=i+1;j<arr.size();j++)
            if(arr[j]<arr[minIdx])
                minIdx=j;
        swap(arr[i],arr[minIdx]);
    }
}

void insertionSort(vector<int> &arr) {
    for(int i=1;i<arr.size();i++) {
        int j=i,key=arr[i];
        for(;j>0 && arr[j-1]>key ;j--)
            arr[j]=arr[j-1];
        arr[j]=key;
    }
}

void quickSortHelper(vector<int> &arr,int start,int end) {
    if(start>=end)
        return;
    int piv=start;
    int left=start+1;
    int right=end;
    while(left<=right) {
        if((arr[left]>arr[piv]) && (arr[piv]>arr[right]))
            swap(arr[left],arr[right]);
        if(arr[left]<=arr[piv])
            left++;
        if(arr[piv]<=arr[right])
            right--;
    }
    swap(arr[piv],arr[right]);
    quickSortHelper(arr,start,right-1);
    quickSortHelper(arr,right+1,end);
}

void quickSort(vector<int> &arr) {
    quickSortHelper(arr,0,arr.size()-1);
}

void combineHelper(vector<int> &arr,int startIdx,int middleIdx,int endIdx,vector<int> &aux) {
    int i=startIdx;
    int j=middleIdx+1;
    int k=startIdx;
    while(i<=middleIdx && j<=endIdx)
        if(aux[i]<aux[j])
            arr[k++]=aux[i++];
        else
            arr[k++]=aux[j++];
    while(i<=middleIdx)
        arr[k++]=aux[i++];
    while(j<=endIdx)
        arr[k++]=aux[j++];
}

void mergeSortHelper(vector<int> &arr,int startIdx,int endIdx,vector<int> &aux) {
    if(startIdx>=endIdx)
        return;
    int middleIdx=startIdx+(endIdx-startIdx)/2;
    mergeSortHelper(aux,startIdx,middleIdx,arr);
    mergeSortHelper(aux,middleIdx+1,endIdx,arr);
    combineHelper(arr,startIdx,middleIdx,endIdx,aux);
}

void mergeSort(vector<int> &arr) {
    vector<int> aux = arr;
    mergeSortHelper(arr,0,arr.size()-1,aux);
}

void siftDown(vector<int> &arr,int curIdx,int endIdx) {
    int leftChildIdx=2*curIdx+1;
    while(leftChildIdx<=endIdx) {
        int rightChildIdx=((2*curIdx+2)<=endIdx)?(2*curIdx+2):-1;
        int idxToSwap;
        if(rightChildIdx!=-1 && (arr[rightChildIdx]>arr[leftChildIdx]))
            idxToSwap=rightChildIdx;
        else
            idxToSwap=leftChildIdx;
        if(arr[idxToSwap]>arr[curIdx]) {
            swap(arr[curIdx],arr[idxToSwap]);
            curIdx=idxToSwap;
            leftChildIdx=2*curIdx+1;
        } else
            return;
    }
}

void heapSort(vector<int> &arr) {
    for(int i=(arr.size()/2)-1;i>=0;i--)
        siftDown(arr,i,arr.size()-1);
    for(int i=arr.size()-1;i>0;i--) {
        swap(arr[0],arr[i]);
        siftDown(arr,0,i-1);
    }
}

int main() {
    vector<int> arr = {5,3,7,0,1,2,5,56,32,15};
    //ONLY RUN ONE AT A TIME
    //----------Algorithms Starts-----------//
    //bubbleSort(arr);
    //selectionSort(arr);
    //insertionSort(arr);
    //quickSort(arr);
    //mergeSort(arr);
    //heapSort(arr);
    //-----------Algorithms End------------//
    for(auto x:arr)
        cout<<x<<" ";
    cout<<endl;
}