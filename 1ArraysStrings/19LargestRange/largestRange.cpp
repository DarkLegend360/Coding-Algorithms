#include <bits/stdc++.h>
using namespace std;

vector<int> largestRange(vector<int> arr) {
	int maxLength=0;
	vector<int> res(2,-1);
	unordered_map<int,bool> mp;
	for(auto x:arr)
		mp[x]=true;
	for(auto x:arr) {
		if(mp[x]) {
			mp[x]=false;
			int curLength=0;
			int left=x;
			while(mp.find(left-1)!=mp.end()) {
				left--;
				curLength++;
				mp[left]=false;
			}
			int right=x;
			while(mp.find(right+1)!=mp.end()) {
				right++;
				curLength++;
				mp[right]=false;
			}
			if(curLength>maxLength) {
				maxLength=curLength;
				res={left,right};
			}
		}
	}
  return res;
}

int main() {
    vector<int> arr = {1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6};
    for(auto x:largestRange(arr))
        cout<<x<<" ";
    cout<<endl;
    return 0;
}