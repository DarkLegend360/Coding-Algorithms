#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>

int knapSackBruteForce(vector<int> &weight, vector<int> &profit, int W, int item) {
	if(W==0 || item==0)
		return 0;
	if(weight[item] > W)
		return knapSackBruteForce(weight, profit, W, item-1);
	int include = knapSackBruteForce(weight, profit, W-weight[item], item-1)+profit[item];
	int exlude = knapSackBruteForce(weight, profit, W, item-1);
	return max(include, exlude);
}

int knapSackWithMem(vector<int> &weight, vector<int> &profit, int W, int item, vvi &memTable) {
	if(W==0 || item==-1)
		return 0;
	if(memTable[item][W]!=-1)
		return memTable[item][W];
	if(weight[item] > W)
		return memTable[item][W]=knapSackWithMem(weight, profit, W, item-1, memTable);
	int include = knapSackWithMem(weight, profit, W-weight[item], item-1, memTable)+profit[item];
	int exlude = knapSackWithMem(weight, profit, W, item-1, memTable);
	return memTable[item][W]= max(include, exlude);
}

int knapSackWithTopDown(vector<int> &weight, vector<int> &profit, int size) {
	vector<vector<int>> dp(weight.size()+1, vector<int>(size+1, 0));
	for(int i=1;i<=weight.size();i++) {
		for(int j=1;j<=size;j++) {
			if(weight[i]>j)
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=max(dp[i-1][j], profit[i]+dp[i-1][j-weight[i]]);
		}
	}
	return dp[weight.size()][size];
}

int main() {
	vector<int> weight = {3, 2, 4};
	vector<int> profit = {6, 8, 7};
	int size = 8;
	//cout<<knapSackBruteForce(weight, profit, size, weight.size()-1)<<endl;
	//WithMem
	//vector<vector<int>> memTable(weight.size(), vector<int>(size+1, -1));
	//cout<<knapSackWithMem(weight, profit, size, weight.size()-1, memTable)<<endl;
	//Top Down Table Method
	cout<<knapSackWithTopDown(weight, profit, size)<<endl;
	return 0;
}