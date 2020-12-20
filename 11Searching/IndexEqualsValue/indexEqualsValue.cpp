#include <bits/stdc++.h>
using namespace std;

int indexEqualsValue(vector<int> arr) {
  int leftIdx=0;
  int rightIdx=arr.size()-1;
  int middleIdx;
  while(leftIdx<=rightIdx) {
    middleIdx=leftIdx+(rightIdx-leftIdx)/2;
    if(arr[middleIdx]<middleIdx)
        leftIdx=middleIdx+1;
    else if(arr[middleIdx]==middleIdx && middleIdx==0)
        return middleIdx;
    else if(arr[middleIdx]==middleIdx && arr[middleIdx-1]<middleIdx-1)
        return middleIdx;
    else
        rightIdx=middleIdx-1;
  }
  return -1;
}


int main() {
    vector<int> arr = {-5, -3, 0, 3, 4, 5, 9};
    cout<<indexEqualsValue(arr)<<endl;
    return 0;
}