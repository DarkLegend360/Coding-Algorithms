#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

void buildSegmentTree(vi &arr, vi &ST, int i, int L, int R) {
	if(L==R) {
		ST[i]=arr[L];
		return;
	}
	int midIdx = L+(R-L)/2;
	buildSegmentTree(arr, ST, 2*i+1, L, midIdx);
	buildSegmentTree(arr, ST, 2*i+2, midIdx+1, R);
	ST[i]=ST[2*i+1]^ST[2*i+2];
}

int getRangeXOR(vi &ST, int i, int sL, int sR, int L, int R) {
	if(L > sR || R < sL)
		return 0;
	if(L <= sL && R >= sR)
		return ST[i];
	int midIdx = sL+(sR-sL)/2;
	int left = getRangeXOR(ST, 2*i+1, sL, midIdx, L, R);
	int right = getRangeXOR(ST, 2*i+2, midIdx+1, sR, L, R);
	return left^right;
}

void updateSegmentTree(vi &ST, int i, int L, int R, vi &arr, int idx, int value) {
	if(L==R) {
		arr[idx]=value;
		ST[i]=value;
		return;
	}
	int midIdx = L+(R-L)/2;
	if(idx>=L && idx<=midIdx)
		updateSegmentTree(ST, 2*i+1, L, midIdx, arr, idx, value);
	else
		updateSegmentTree(ST, 2*i+2, midIdx+1, R, arr, idx, value);
	ST[i]=ST[2*i+1]^ST[2*i+2];
}

int main() {
	vector<int> arr = {8, 5, 3, 7, 6};
	vector<int> ST(4*arr.size());
	//Build Segment Tree
	buildSegmentTree(arr, ST, 0, 0, arr.size()-1);
	//Query
	cout<<getRangeXOR(ST, 0, 0, arr.size()-1, 0, 2)<<"\n";
	//Update Segment Tree
	updateSegmentTree(ST, 0, 0, arr.size()-1, arr, 2, 5);
	//Query
	cout<<getRangeXOR(ST, 0, 0, arr.size()-1, 0, 2)<<"\n";
	return 0;
}