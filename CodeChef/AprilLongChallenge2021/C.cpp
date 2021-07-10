#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) {
		int n, k;
		cin>>n>>k;

		string s;
		cin>>s;	
		int flag=true;
		if(k==1) {
			for(int i=0;i<n&&flag;i++) {
				if(s[i]=='*') {
					cout<<"YES"<<"\n";
					flag=false;
				}
			}
			if(flag)
				cout<<"NO"<<"\n";
			continue;
		}
		int leftIdx=0;
		int rightIdx=1;
		while(rightIdx<s.size() && flag) {
			if(s[leftIdx]==s[rightIdx] && s[rightIdx]=='*') {
				if((rightIdx-leftIdx+1)==k) {
					cout<<"YES"<<"\n";
					flag=false;
					break;
				}
			} else {
				leftIdx=rightIdx;
			}
			rightIdx++;
		}
		if(flag)
			cout<<"NO"<<"\n";
	}
	return 0;
}