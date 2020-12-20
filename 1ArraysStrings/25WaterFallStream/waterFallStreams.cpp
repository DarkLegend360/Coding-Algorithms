#include <bits/stdc++.h>
using namespace std;

vector<double> waterfallStreams(vector<vector<double>> arr, int source) {
    vector<double> prevRow = arr[0];
    prevRow[source]=100;
    for(int i=1;i<arr.size();i++) {
        vector<double> curRow = arr[i];
        for(int j=0;j<arr[i].size();j++) {
            if(prevRow[j]<=1)
                continue;
            if(curRow[j]!=1) {
                curRow[j]+=prevRow[j];
                continue;
            }
            int leftIdx=j;
            while(leftIdx-1>=0) {
                leftIdx--;
                if(prevRow[leftIdx]==1)
                    break;
                if(curRow[leftIdx]!=1){
                    curRow[leftIdx]+=prevRow[j]/2;
                    break;
                }
            }
            int rightIdx=j;
            while(rightIdx+1<arr[i].size()) {
                rightIdx++;
                if(prevRow[rightIdx]==1)
                    break;
                if(curRow[rightIdx]!=1) {
                    curRow[rightIdx]+=prevRow[j]/2;
                    break;
                }
            }
        }
        prevRow=curRow;
    }
    return prevRow;
}

int main() {
    vector<vector<double>> arr ={
            {0, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 0, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0}
    };
    int source=3;
    for(auto x:waterfallStreams(arr,source))
        cout<<x<<" ";
    cout<<endl;
    return 0;
}