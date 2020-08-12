#include <bits/stdc++.h>
using namespace std;

int shiftedBinarySearch(vector<int> &arr, int &target) {
	int leftIdx=0;
	int rightIdx=arr.size()-1;
	while(leftIdx<=rightIdx) {
		int midIdx=leftIdx+(rightIdx-leftIdx)/2;
		if(arr[midIdx]==target)	return midIdx;
		else if(arr[leftIdx]<=arr[midIdx]) {
			if(target>=arr[leftIdx] && target<arr[midIdx])
				rightIdx=midIdx-1;
			else 
				leftIdx=midIdx+1;
		} else {
			if(target<=arr[rightIdx] && target>arr[midIdx])
				leftIdx=midIdx+1;
			else
				rightIdx=midIdx-1;
		}
	}
	return -1;
}

int main() {
    int target=72;
    vector<int> arr = {45, 61, 71, 72, 73, 0, 1, 21, 33, 37};
    cout<<shiftedBinarySearch(arr,target)<<endl;
    return 0;
}