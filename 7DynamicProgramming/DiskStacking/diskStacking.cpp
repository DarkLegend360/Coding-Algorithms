#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> diskStacking(vector<vector<int>> disks) {
    sort(disks.begin(),disks.end(),[](auto &a,auto &b){return a[2]<b[2];});
    vector<int> heights(disks.size());
    vector<int> sequence(disks.size(),-1);
    for(int i=0;i<disks.size();i++)
        heights[i]=disks[i][2];
    for(int i=0;i<disks.size();i++) {
        for(int j=0;j<i;j++) {
            if(disks[j][0]<disks[i][0] && disks[j][1]<disks[i][1] && disks[j][2]<disks[i][2]) {
                if(heights[i]<disks[i][2]+heights[j]) {
                    heights[i]=disks[i][2]+heights[j];
                    sequence[i]=j;
                }
            }
        }
    }
    int maxHeight=0;
    int maxHeightIdx=0;
    for(int i=0;i<disks.size();i++){
        if(maxHeight<heights[i]) {
            maxHeight=heights[i];
            maxHeightIdx=i;
        }
    }

    vector<vector<int>> result;
    int i=maxHeightIdx;
    while(i!=-1) {
        result.insert(result.begin(),disks[i]);
        i=sequence[i];
    }
    return result;
}

int main() {
    vector<vector<int>> disks = {{2, 1, 2}, {3, 2, 3}, {2, 2, 8}, {2, 3, 4}, {1, 3, 1}, {4, 4, 5}};
    for(auto x: diskStacking(disks))
        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
    return 0;
}