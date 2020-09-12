#include <bits/stdc++.h>
using namespace std;

string longestSubstringWithoutDuplication(string str) {
  unordered_map<char,int> lastSeen;
	vector<int> longest{0,1};
	int startIdx=0;
	for(int i=0;i<str.size();i++) {
		if(lastSeen.find(str[i])!=lastSeen.end())
			startIdx=max(startIdx,lastSeen[str[i]]+1);
		if((i-startIdx+1)>longest[1])
			longest={startIdx,i-startIdx+1};
		lastSeen[str[i]]=i;
	}
  return str.substr(longest[0],longest[1]);
}

int main() {
    cout<<longestSubstringWithoutDuplication("mynameisdarklegend360");
    return 0;
}
