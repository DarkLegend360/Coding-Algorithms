#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> arr, int targetSum) {
    vector<vector<int>> result;
    unordered_map<int,vector<vector<int>>> myMap;
    for(int i=1;i<arr.size()-1;i++) {
        for(int j=i+1;j<arr.size();j++) {
            int keyToFind=targetSum-arr[i]-arr[j];
            if(myMap.find(keyToFind)!=myMap.end()) {
                for(auto x : myMap[keyToFind]) {
                    vector<int> quad=x;
                    quad.push_back(arr[i]);
                    quad.push_back(arr[j]);
                    result.push_back(quad);
                }
            }
        }
        for(int j=0;j<i;j++) {
            int keyToAdd = arr[i]+arr[j];
            if(myMap.find(keyToAdd)!=myMap.end())
                myMap[keyToAdd].push_back({arr[i],arr[j]});
            else
                myMap[keyToAdd]=vector<vector<int>>{{arr[i],arr[j]}};
        }
    }
    return result;
}

int main() {
    vector<int> arr ={7, 6, 4, -1, 1, 2};
    int target=16;
    for(auto x:fourNumberSum(arr,target)) {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}