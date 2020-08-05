#include <bits/stdc++.h>
using namespace std;

int waterArea(vector<int> heights) {
    int n=heights.size();
    if(n<3) return 0;
    int i=0,j=n-1;
    int maxL=heights[i++],maxR=heights[j--];
    int res=0;
    while(i<=j) {
        if(maxL<maxR) {
            if(heights[i]<maxL)
                res+=maxL-heights[i];
            maxL=max(heights[i++],maxL);
        } else {
            if(heights[j]<maxR)
                res+=maxR-heights[j];
            maxR=max(heights[j--],maxR);
        }
    }
  return res;
}

int main() {
    vector<int> arr={0,8,0,0,5,0,0,10,0,0,1,1,0,3};
    cout<<waterArea(arr)<<endl;
    return 0;
}