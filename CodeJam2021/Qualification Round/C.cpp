#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int x=1;x<=t;x++) {
		int n;
		cin>>n;
		int k;
		cin>>k;
		vector<int> arr(n,0);
		for(int i=1;i<=n;i++)
			arr[i-1]=i;
		bool flag=false;
		do {
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
			if(score==k) {
				cout<<"Case #"<<x<<": ";
				for(int i=0;i<n;i++)
					if(i<n-1)
						cout<<arr[i]<<" ";
					else
						cout<<arr[i]<<"\n";
				flag=true;
				break;
			}   
		} while(next_permutation(arr.begin(), arr.end()));
	if(!flag)
		cout<<"Case #"<<x<<": IMPOSSIBLE"<<"\n";
	}
	return 0;
}