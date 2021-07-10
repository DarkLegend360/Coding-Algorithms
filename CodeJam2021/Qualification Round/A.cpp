#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int x=1;x<=t;x++) {
		int n;
		cin>>n;
		vector<int> arr(n,0);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int score=0;
		for(int i=0;i<n-1;i++) {
			int minIdx=i;
			int minValue=arr[i];
			for(int j=i;j<n;j++) {
				if(minValue>arr[j]) {
					minValue=arr[j];
					minIdx=j;
				}
			}
			score+=(minIdx-i+1);
			int leftIdx=i;
			int rightIdx=minIdx;
			while(leftIdx<rightIdx)
				swap(arr[leftIdx++],arr[rightIdx--]);
		}
		cout<<"Case #"<<x<<": "<<score<<"\n";
	}
	return 0;
}