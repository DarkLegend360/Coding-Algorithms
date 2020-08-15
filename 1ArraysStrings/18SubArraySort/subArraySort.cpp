#include <bits/stdc++.h>
using namespace std;

bool isUnSafe(vector<int> &arr,int i) {
	if(i==0)
		return arr[i]>arr[i+1];
	if(i==arr.size()-1)
		return arr[arr.size()-1]<arr[arr.size()-2];
	return (arr[i-1]>arr[i]) || (arr[i]>arr[i+1]);
}

vector<int> subarraySort(vector<int> arr) {
		int n=arr.size();
		if(n<=1) return {-1,-1};
		int minElement=INT_MAX;
    int maxElement=INT_MIN;
    for(int i=0;i<n;i++) {
        if(isUnSafe(arr,i)) {
            minElement=min(minElement,arr[i]);
            maxElement=max(maxElement,arr[i]);
        }
    }
    if(minElement==INT_MAX) 
        return {-1,-1};
    int leftIdx=0;
    while(minElement>=arr[leftIdx])
        leftIdx++;
    int rightIdx=n-1;
    while(maxElement<=arr[rightIdx])
        rightIdx--;
    return {leftIdx,rightIdx};
}

int main() {
    vector<int> arr = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    for(auto x:subarraySort(arr))
        cout<<x<<" ";
    cout<<endl;
    return 0;
}