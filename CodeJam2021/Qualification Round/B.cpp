#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int w=1;w<=t;w++) {
		int minCost=0;
		int x, y;
		cin>>x>>y;
		string s;
		cin>>s;

		for(int i=0;i<s.size();i++) {
			if(s[i]=='?') {
				if(i-1>=0 && (s[i-1]=='C' || s[i-1]=='?'))
					s[i]='C';
				else
					s[i]='J';
			}
		}
		for(int i=0;i<s.size()-1;i++) {
			if(s.substr(i,i+2)=="CJ")
				minCost+=x;
			if(s.substr(i,i+2)=="JC")
				minCost+=y;
		}
		cout<<s<<" "<<minCost<<endl;
		//cout<<"Case #"<<w<<": "<<minCost<<"\n";
	}
	return 0;
}