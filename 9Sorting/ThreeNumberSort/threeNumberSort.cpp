#include <bits/stdc++.h>
using namespace std;

vector<int> threeNumberSort(vector<int> arr, vector<int> order) {
    int idx=0;
    for(int i=0;i<2;i++) {
        int target=order[i];
        for(int j=0;j<arr.size();j++)
            if(arr[j]==target)
                swap(arr[idx++],arr[j]);
    }
    return arr;
}

vector<int> threeNumberSort2(vector<int> arr, vector<int> order) {
    int firstIdx=0;
    int secondIdx=0;
    int thirdIdx=arr.size()-1;
    int firstValue=order[0];
    int secondValue=order[1];
    while(secondIdx<=thirdIdx) {
        int value = arr[secondIdx];
        if(value==firstValue)
            swap(arr[secondIdx++],arr[firstIdx++]);
        else if(value == secondValue)
            secondIdx++;
        else
            swap(arr[secondIdx],arr[thirdIdx--]);
    }
    return arr;
}

int main() {
    vector<int> arr = {1, 0, 0, -1, -1, 0, 1, 1};
    vector<int> order = {0, 1, -1};
    for(auto x: threeNumberSort2(arr,order))
        cout<<x<<" ";
    cout<<endl;
    return 0;
}