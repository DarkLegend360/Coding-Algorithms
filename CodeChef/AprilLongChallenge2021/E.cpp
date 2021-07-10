#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) {
		string s;
		cin>>s;
		int n = s.size();
		vector<int> nums;
		unordered_set<int> mySet;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<=n;j++) {
				string sub = s.substr(i,j-i);
				int newNum = stoi(sub, nullptr, 2);
				mySet.insert(newNum);
			}
		int maxElement=INT_MIN;
    	for (auto itr = mySet.begin(); itr != mySet.end(); itr++)
        	maxElement= max(maxElement, *itr);
		for(int i=1;i<=maxElement+1;i++) {
			if(mySet.find(i)==mySet.end()) {
				cout<<i<<"\n";
				break;
			}
		}
	}
	return 0;
}