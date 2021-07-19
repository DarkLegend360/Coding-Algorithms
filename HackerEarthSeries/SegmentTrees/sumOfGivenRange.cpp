#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

int buildSegmentTree(vi &arr, int L, int R, vi &ST, int i) {
	if(L==R) {
		ST[i]=arr[L];
		return ST[i];
	}
	int midIdx = L+(R-L)/2;
	int left = buildSegmentTree(arr, L, midIdx, ST, 2*i+1);
	int right = buildSegmentTree(arr, midIdx+1, R, ST, 2*i+2);
	ST[i]=left + right;
	return ST[i];
}

int getRangeSum(vi &ST, int i, int sL, int sR, int L, int R) {
	if(L>sR || R<sL)
		return 0;
	if(L<=sL && R>=sR)
		return ST[i];
	int midIdx=sL+(sR-sL)/2;
	int left = getRangeSum(ST, 2*i+1, sL, midIdx, L, R);
	int right = getRangeSum(ST, 2*i+2, midIdx+1, sR, L, R);
	return left+right;
}

void updateHelper(vi &ST, int i, int L, int R, int idx, int diff) {
	if(idx<L || R<idx)
		return;
	ST[i]+=diff;
	if(L==R)
		return;
	int midIdx=L+(R-L)/2;
	updateHelper(ST, 2*i+1, L, midIdx, idx, diff);
	updateHelper(ST, 2*i+2, midIdx+1, R, idx, diff);
}

void updateSegmentTree(vi &ST, vi &arr, int idx, int newValue) {
	int diff = newValue - arr[idx];
	arr[idx] = newValue;
	updateHelper(ST, 0, 0, arr.size()-1, idx, diff);
}

int main() {
	vector<int> arr = {1, 2, 5, 6, 7, 9};
	vector<int> ST(4*arr.size());
	buildSegmentTree(arr, 0, arr.size()-1, ST, 0);
	//Range Sum
	cout<<getRangeSum(ST, 0, 0, arr.size()-1, 0, 6)<<endl;
	//Update Segment Tree
	updateSegmentTree(ST, arr, 3, 14);
	//Range Sum
	cout<<getRangeSum(ST, 0, 0, arr.size()-1, 0, 6)<<endl;
	return 0;
}