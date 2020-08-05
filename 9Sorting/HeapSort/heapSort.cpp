#include <bits/stdc++.h>
using namespace std;

void siftDown(vector<int> &arr,int curIdx,int endIdx) {
	int leftChildIdx = curIdx*2+1;
	while(leftChildIdx<=endIdx) {
		int rightChildIdx = (curIdx*2+2<=endIdx?curIdx*2+2:-1);
		int idxToSwap;
		if(rightChildIdx!=-1 && arr[rightChildIdx]>arr[leftChildIdx])
			idxToSwap=rightChildIdx;
		else
			idxToSwap=leftChildIdx;
		if(arr[idxToSwap] > arr[curIdx]) {
			swap(arr[idxToSwap],arr[curIdx]);
			curIdx=idxToSwap;
			leftChildIdx=curIdx*2+1;
		} else 
			return;
	}
}

void buildMaxHeap(vector<int> &arr) {
	for(int i=(arr.size()/2)-1;i>=0;i--)
		siftDown(arr,i,arr.size()-1);
}
vector<int> heapSort(vector<int> array) {
  buildMaxHeap(array);
	for(int i=array.size()-1;i>=1;i--) {
		swap(array[0],array[i]);
		siftDown(array,0,i-1);
	}
	return array;
}

int main() {
    vector<int> arr={5,7,3,2,76,9,0,1,6,13,34,21};
    arr=heapSort(arr);
    for(auto x:arr)
        cout<<x<<" ";
    cout<<endl;
}