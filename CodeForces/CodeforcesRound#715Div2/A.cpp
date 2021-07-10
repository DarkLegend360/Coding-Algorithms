#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int ele;
		vector<int> odd,even;
		for(int i=0;i<n;i++) {
			cin>>ele;
			if(ele%2==0)
				even.push_back(ele);
			else
				odd.push_back(ele);
		}
		sort(even.begin(), even.end());
		sort(odd.begin(), odd.end());
		int oddIdx=0;
		int evenIdx=even.size()-1;
		while(oddIdx<odd.size() && evenIdx>=0)
			cout<<odd[oddIdx++]<<" "<<even[evenIdx--]<<" ";
		while(oddIdx<odd.size())
			if(oddIdx!=odd.size()-1)
				cout<<odd[oddIdx++]<<" ";
			else
				cout<<odd[oddIdx++];
		while(evenIdx>=0)
			if(evenIdx!=0)
				cout<<even[evenIdx--]<<" ";
			else 
				cout<<even[evenIdx--];
		cout<<"\n";
	}
	return 0;
}