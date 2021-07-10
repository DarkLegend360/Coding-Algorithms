#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	for(int x=1;x<=t;x++) {
		long long int result=0;
		long long int G;
		cin>>G;
		long long int leftIdx=1;
		long long int rightIdx=2;
		long long int curSum=leftIdx;
		while(rightIdx<=G) {
			while(curSum>G && leftIdx<rightIdx)
				curSum-=leftIdx++;
			if(curSum==G)
				result++;
			curSum+=rightIdx++;
		}
		while(leftIdx<rightIdx && curSum>G)
			curSum-=leftIdx++;
		if(curSum==G)
			result++;
		cout<<"Case #"<<x<<": "<<result<<"\n";
	
}	return 0;
}