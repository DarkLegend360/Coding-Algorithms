#include <bits/stdc++.h>
using namespace std;

int maxProfitWithKTransactions(vector<int> prices, int k) {
    if(!prices.size()) return 0;
    vector<vector<int>> profit(k+1,vector<int>(prices.size(),0));
    for(int t=1;t<=k;t++) {
        int maxThusFar=INT_MIN;
        for(int d=1;d<prices.size();d++) {
            maxThusFar=max(maxThusFar,profit[t-1][d-1]-prices[d-1]);
            profit[t][d]=max(profit[t][d-1],prices[d]+maxThusFar);
        }
    }
    return profit[k][prices.size()-1];
}

int main() {
    vector<int> prices ={5, 11, 3, 50, 60, 90};
    int k=2;
    cout<<maxProfitWithKTransactions(prices,k)<<endl;
    return 0;
}