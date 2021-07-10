// #include <bits/stdc++.h>
// using namespace std;

// bool isValid(string s1, string s2, int a, int b) {
// 	int i=0, j = 0;
//     for(;i<b&&j<a;i++)
//         if (s1[j]==s2[i])
//             j++;
//  	return (j == a);
// }

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	string virusComp;
// 	cin>>virusComp;
// 	int n;
// 	cin>>n;
// 	string input;
// 	for(int i=0;i<n;i++) {
// 		cin>>input;
// 		if(isValid(input, virusComp, input.size(), virusComp.size()))
// 			cout<<"POSITIVE"<<"\n";
// 		else
// 			cout<<"NEGATIVE"<<"\n";
// 	}
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<bool> sieve(MAX, true);
	sieve[0]=sieve[1]=false;
	for(int i=2;i*i<=MAX;i++)
		if(sieve[i])
			for(int j=i*i;j<=MAX;j+=i)
				sieve[j]=false;
	int t;
	cin>>t;
	int L, R;
	while(t--) {
		cin>>L>>R;
		int leftPrime=-1;
		int rightPrime=-1;
		for(int i=L;i<=R;i++)
			if(sieve[i]) {
				leftPrime=i;
				break;
			}
		for(int i=R;i>=L;i--)
			if(sieve[i]){
				rightPrime=i;
				break;
			}
		int result = rightPrime-leftPrime;
		if(leftPrime==-1 && rightPrime==-1)
			cout<<-1<<"\n";
		else if(leftPrime==rightPrime)
			cout<<0<<"\n";
		else
			cout<<result<<"\n";
	}
	return 0;
}