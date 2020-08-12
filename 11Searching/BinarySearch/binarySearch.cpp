#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr,int target) {
    int leftIdx=0;
    int rightIdx=arr.size()-1;
    while(leftIdx<=rightIdx) {
        int midIdx=leftIdx+(rightIdx-leftIdx)/2;
        if(target==arr[midIdx])
            return midIdx;
        else if(target<arr[midIdx])
            rightIdx=midIdx-1;
        else   
            leftIdx=midIdx+1;
    }
    return -1;
}

int main() {
     int target=33;
     vector<int> arr={2,4,6,8,15,33,57,143};
     cout<<binarySearch(arr,target)<<endl;
     return 0;
 }