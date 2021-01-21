#include <bits/stdc++.h>
using namespace std;

vector<int> sortKSortedArray(vector<int> arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0;i<=k && i<arr.size();i++)
        minHeap.push(arr[i]);
    for(int i=0;i<arr.size();i++) {
        if(i>0 && (i+k)<arr.size())
            minHeap.push(arr[i+k]);
        arr[i]=minHeap.top();
        minHeap.pop();
    }
    return arr;
}

int main() {
    vector<int> input = {3, 2, 1, 5, 4, 7, 6, 5};
    int k = 3;
    vector<int> expected = {1, 2, 3, 4, 5, 5, 6, 7};
    auto actual = sortKSortedArray(input, k);
    cout<<(expected == actual)<<endl;
    return 0;
}