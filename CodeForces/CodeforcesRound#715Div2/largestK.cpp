/*
Largest K such that both K and -K exist in array
Input: [3, 2, -2, 5, -3]
Output: 3
Input: [1, 2, 3, -4]
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

void hashMethod(vector<int> arr) {
	int maxValue=0;
	unordered_set<int> set;
	for(auto val : arr)
		if(set.find(val*-1)!=set.end())
			maxValue=max(maxValue, abs(val));
		else
			set.insert(val);
	cout<<maxValue<<"\n";
}

void sortMethod(vector<int> arr) {
	int maxValue=0;
	sort(arr.begin(), arr.end());
	int leftIdx=0;
	int rightIdx=arr.size()-1;
	while(leftIdx<rightIdx) {
		int sum = arr[leftIdx]+arr[rightIdx];
		if(sum==0){
					maxValue=max(maxValue, arr[rightIdx]);
					leftIdx++;
					rightIdx--;
		}
		else if(sum<0)
			leftIdx++;
		else
			rightIdx--;
	}
	cout<<maxValue<<"\n";
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> arr ={3, 2, -2, 5, -3};
	//hashMethod(arr);
	sortMethod(arr);
	return 0;
}