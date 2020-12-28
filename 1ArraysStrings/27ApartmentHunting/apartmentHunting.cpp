#include <bits/stdc++.h>
using namespace std;

//Time O(B^2 * R)  Space O(1)
int apartmentHunting(vector<unordered_map<string, bool>> blocks, vector<string> reqs) {
    int minBlock=0;
    int minDistance=INT_MAX;
    for(int i=0;i<blocks.size();i++) {
        int maxDistAtCurBlock=INT_MIN;
        for(auto req : reqs) {
            int closestReqDistance=INT_MAX;
            for(int j=0;j<blocks.size();j++)
                if(blocks[j][req])
                    closestReqDistance=min(closestReqDistance,abs(j-i));
            maxDistAtCurBlock=max(maxDistAtCurBlock,closestReqDistance);
        }
        if(minDistance>maxDistAtCurBlock) {
            minBlock=i;
            minDistance=maxDistAtCurBlock;
        }
    }
    return minBlock;
}

vector<int> getMinDistances(vector<unordered_map<string, bool>> blocks, string req) {
    vector<int> minDistance(blocks.size());
    int closestReqDistance = INT_MAX;
    for(int i=0;i<blocks.size();i++) {
        if(blocks[i][req])
            closestReqDistance=i;
        minDistance[i]=abs(closestReqDistance-i);
    }
    for(int i=blocks.size()-1;i>=0;i--) {
        if(blocks[i][req])
            closestReqDistance=i;
        minDistance[i]=min(minDistance[i],abs(closestReqDistance-i));
    }
    return minDistance;
}

int apartmentHunting2(vector<unordered_map<string, bool>> blocks, vector<string> reqs) {
    int minBlock=0;
    int minValue=INT_MAX;
    vector<vector<int>> minDistancesFromBlocks;
    for(auto req : reqs)
        minDistancesFromBlocks.push_back(getMinDistances(blocks,req));
    for(int i=0;i<blocks.size();i++) {
        int minDistanceAtCurrentBlock=INT_MIN;
        for(auto distance : minDistancesFromBlocks)
            minDistanceAtCurrentBlock=max(minDistanceAtCurrentBlock,distance[i]);
        if(minDistanceAtCurrentBlock<minValue) {
            minValue=minDistanceAtCurrentBlock;
            minBlock=i;
        }
    }
    return minBlock;
}

int main() {
    vector<unordered_map<string, bool>> blocks(5);
    blocks[0].insert({"gym", false});
    blocks[0].insert({"school", true});
    blocks[0].insert({"store", false});
    blocks[1].insert({"gym", true});
    blocks[1].insert({"school", false});
    blocks[1].insert({"store", false});
    blocks[2].insert({"gym", true});
    blocks[2].insert({"school", true});
    blocks[2].insert({"store", false});
    blocks[3].insert({"gym", false});
    blocks[3].insert({"school", true});
    blocks[3].insert({"store", false});
    blocks[4].insert({"gym", false});
    blocks[4].insert({"school", true});
    blocks[4].insert({"store", true});
    vector<string> reqs = {"gym", "school", "store"};
    cout<<apartmentHunting2(blocks, reqs)<<endl;
    return 0;
}