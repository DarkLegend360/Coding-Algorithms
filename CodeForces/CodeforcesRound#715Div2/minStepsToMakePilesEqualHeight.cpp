/*
Input  : {1, 1, 2, 2, 2, 3, 3, 3, 4, 4};
Output : 15
Input: piles = {5, 2, 1}
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> s={1, 1, 2, 2, 2, 3, 3, 3, 4, 4};
	sort(s.begin(), s.end(), greater<int>());
	int minNoOfSteps=0;
	for(int i=1;i<s.size();i++)
		minNoOfSteps+=(s[i-1]!=s[i])?i:0;
	cout<<minNoOfSteps<<"\n";
	return 0;
}