#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) {
		double k1,k2,k3,v;
		cin>>k1>>k2>>k3>>v;
		double result = 100.0/(k1*k2*k3*v);
		result = round(result*100.0)/100.0;
		cout<<result<<endl;
		cout<<(result<9.58?"YES":"NO")<<"\n";
	}
	return 0;
}