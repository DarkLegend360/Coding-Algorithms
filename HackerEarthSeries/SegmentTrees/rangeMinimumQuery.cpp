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
	ST[i]= min(left, right);
	return ST[i];
}

int getRangeMinimum(vi &ST, int i, int sL, int sR, int L, int R) {
	if(L > sR || R < sL)
		return INT_MAX;
	if(L <= sL && R >= sR)
		return ST[i];
	int midIdx=sL+(sR-sL)/2;
	int left = getRangeMinimum(ST, 2*i+1, sL, midIdx, L, R);
	int right = getRangeMinimum(ST, 2*i+2, midIdx+1, sR, L, R);
	return min(left, right);
}

void updateSegmentTree(vi &ST, int i, int L, int R, vi &arr, int value, int idx) {
	if(L==R) {
		arr[idx]=value;
		ST[i]=value;
		return;
	}
	int midIdx= L+(R-L)/2;
	if(idx >= L && idx <= midIdx)
		updateSegmentTree(ST, 2*i+1, L, midIdx, arr, value, idx);
	else
		updateSegmentTree(ST, 2*i+2, midIdx+1, R, arr, value, idx);
	ST[i]= min(ST[2*i+1], ST[2*i+2]);
}

int main() {
	vector<int> arr = {5, 2, 5, 1, 3};
	vector<int> ST(4*arr.size());
	//Build Segment Tree
	buildSegmentTree(arr, 0, arr.size()-1, ST, 0);
	//Query
	cout<<getRangeMinimum(ST, 0, 0, arr.size()-1, 0, 4)<<"\n";
	//Update Segment Tree
	updateSegmentTree(ST, 0, 0, arr.size()-1, arr, 5, 3);
	//Query
	cout<<getRangeMinimum(ST, 0, 0, arr.size()-1, 0, 4)<<"\n";
	return 0;
}