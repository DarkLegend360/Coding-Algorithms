#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2,-1);
    int i=0,j=nums.size()-1;
    while(i<=j) {
        int mid=i+(j-i)/2;
        if(target<=nums[mid]) j=mid-1;
        else i=mid+1;
        if(target==nums[mid]) res[0]=mid;
    }
    i=0,j=nums.size()-1;
    while(i<=j) {
        int mid=i+(j-i)/2;
        if(target>=nums[mid]) i=mid+1;
        else j=mid-1;
        if(nums[mid]==target) res[1]=mid;
    }
    return res;
}


int main() {
    vector<int> arr = {0, 1, 21, 33, 45, 45, 45, 45, 45, 45, 61, 71, 73};
    int target=45;
    for(auto x:searchRange(arr,target))
        cout<<x<<" ";
    cout<<endl;
    return 0;
}