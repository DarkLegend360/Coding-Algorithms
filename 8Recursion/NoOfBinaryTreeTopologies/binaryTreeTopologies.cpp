#include <bits/stdc++.h>
using namespace std;

int helper(int n, vector<int> &cache) {
	if(cache[n]!=-1)
		return cache[n];
	int trees=0;
	for(int left=0;left<n;left++) {
		int right=n-1-left;
		trees+=helper(left,cache) * helper(right,cache);
	}
	cache[n]=trees;
	return trees;
}

int numberOfBinaryTreeTopologies(int n) {
  vector<int> cache(n+1,-1);
	cache[0]=1;
  return helper(n,cache);
}
