#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int num;
    int numIdx;
    int arrIdx;
    Node(int num,int numIdx,int arrIdx) {
        this->num=num;
        this->arrIdx=arrIdx;
        this->numIdx=numIdx;
    }
};

class myComp{
    public:
    int operator() (const Node &a,const Node &b) {
        return a.num>b.num;
    }
};

vector<int> mergeSortedArrays(vector<vector<int>> arr) {
    priority_queue<Node,vector<Node>,myComp> minHeap;
    vector<int> result;
    for(int i=0;i<arr.size();i++)
        if(arr[i].size())
            minHeap.push(Node(arr[i][0],0,i));
    while(!minHeap.empty()) {
        Node current = minHeap.top();
        minHeap.pop();
        result.push_back(current.num);
        if(current.numIdx!=(arr[current.arrIdx].size()-1))
            minHeap.push(Node(arr[current.arrIdx][current.numIdx+1],current.numIdx+1,current.arrIdx));
    }
  return result;
}

int main() {
    vector<vector<int>> arr = {{1, 5, 9, 21}, {-1, 0}, {-124, 81, 121}, {3, 6, 12, 20, 150}};
    for(auto x:mergeSortedArrays(arr))
        cout<<x<<" ";
    cout<<endl;
    return 0;
}