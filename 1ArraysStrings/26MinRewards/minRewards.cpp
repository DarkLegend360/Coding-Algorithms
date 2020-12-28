#include <bits/stdc++.h>
using namespace std;

int minRewards(vector<int> scores) {
    vector<int> arr(scores.size(),1);
    for(int i=1;i<arr.size();i++)
        if(scores[i-1]<scores[i])
            arr[i]=arr[i-1]+1;
    for(int i=scores.size()-2;i>=0;i--)
        if(scores[i]>scores[i+1])
            arr[i]=max(arr[i],arr[i+1]+1);
    int minRewards=0;
    for(int i=0;i<arr.size();i++)
        minRewards+=arr[i];
    return minRewards;
}

int main() {
    vector<int> arr = {8, 4, 2, 1, 3, 6, 7, 9, 5};
    cout<<minRewards(arr)<<endl;
    return 0;
}