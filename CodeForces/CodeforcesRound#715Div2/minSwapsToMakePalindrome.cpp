#include <bits/stdc++.h>
using namespace std;

/*
mamad    3
asflkj   -1
aabb	 2
ntiin	 1
eeeaa	 3
*/


int minNoOfSwaps(string s) {
	int minNoOfSwaps=0;
	bool foundCenter = false;
	int leftIdx=0;
	int rightIdx = s.size()-1;
	while(leftIdx<s.size()/2) {
		int searcher = rightIdx;
		while(searcher>leftIdx && s[searcher]!=s[leftIdx])
			searcher--;
		if(leftIdx==searcher) {
			if(foundCenter && islower(s[searcher]))
				return -1;
			else {
				foundCenter=true;
				int middleIdx=s.size()/2;
				while(middleIdx!=searcher) {
					swap(s[searcher], s[searcher+1]);
					searcher++;
					minNoOfSwaps++;
				}
				s[middleIdx]=toupper(s[middleIdx]);
			}
		} else {
			while(searcher!=rightIdx) {
				swap(s[searcher], s[searcher+1]);
				searcher++;
				minNoOfSwaps++;
			}
			leftIdx++;
			rightIdx--;
		}
	}
	return minNoOfSwaps;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) {
		string s;
		cin>>s;
		int result = minNoOfSwaps(s);
		reverse(s.begin(), s.end());
		result=min(result, minNoOfSwaps(s));
		cout<<result<<"\n";
	}
}