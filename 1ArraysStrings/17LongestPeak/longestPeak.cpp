#include <bits/stdc++.h>
using namespace std;

int longestPeak(vector<int> arr) {
	if(arr.size()<3) return 0;
  int len=0;
	for(int i=1;i<arr.size()-1;)
		if(arr[i-1]<arr[i] && arr[i]> arr[i+1]) {
			int curPeak=0;
			int idx=i;
			while(idx>0 && (arr[idx-1]<arr[idx]))
				idx--;
			curPeak=i-idx;
			idx=i;
			while(idx<arr.size()-1 && (arr[idx]>arr[idx+1]))
				idx++;
			curPeak+=idx-i;
			len=max(len,curPeak+1);
            i=idx;
		} else
            i++;
	return len;
}


int main() {
    vector<int> arr = {1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
    cout<<longestPeak(arr)<<endl;
    return 0;
}