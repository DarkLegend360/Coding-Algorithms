#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    string id;
    int row,col,value;
    int distanceFromStart;
    int estimatedDistanceToEnd;
    Node *cameFrom;
    Node(int row, int col, int value) {
        this->id=to_string(row)+"-"+to_string(col);
        this->row=row;
        this->col=col;
        this->value=value;
        this->distanceFromStart=INT_MAX;
        this->estimatedDistanceToEnd=INT_MAX;
				this->cameFrom=NULL;
    }
};

class MinHeap {
    public:
    vector<Node *> heap;
    unordered_map<string,int> nodePositionInHeap;
    MinHeap(vector<Node *> arr) {
        for(int i=0;i<arr.size();i++)
            nodePositionInHeap[arr[i]->id]=i;
        heap=buildHeap(arr);
    }
    vector<Node *> buildHeap(vector<Node *> &arr) {
			int firstParentIdx=(arr.size()-2)/2;
        for(int currentIdx=firstParentIdx+1;currentIdx>=0;currentIdx--)
            siftDown(currentIdx,arr.size()-1,arr);
        return arr;
    }
    void siftDown(int currentIdx, int endIdx, vector<Node *> &arr) {
        int leftChildIdx=currentIdx*2+1;
        while(leftChildIdx<=endIdx) {
            int rightChildIdx=((currentIdx*2+2)<=endIdx)?currentIdx*2+2:-1;
            int idxToSwap;
            if(rightChildIdx!=-1 && (arr[rightChildIdx]->estimatedDistanceToEnd<heap[leftChildIdx]->estimatedDistanceToEnd))
                idxToSwap=rightChildIdx;
            else
                idxToSwap=leftChildIdx;
            if(arr[idxToSwap]->estimatedDistanceToEnd < arr[currentIdx]->estimatedDistanceToEnd) {
                swap(currentIdx,idxToSwap);
                currentIdx=idxToSwap;
                leftChildIdx=currentIdx*2+1;
            } else
                return;
        }
    }
    bool isEmpty() {
        return heap.size()==0;
    }
    void siftUp(int currentIdx) {
        int parentIdx=(currentIdx-1)/2;
        while((currentIdx>0) && (heap[currentIdx]->estimatedDistanceToEnd<heap[parentIdx]->estimatedDistanceToEnd)) {
            swap(currentIdx,parentIdx);
            currentIdx=parentIdx;
            parentIdx=(currentIdx-1)/2;
        }
    }
    Node *remove() {
        if(isEmpty())
            return NULL;
        swap(0,heap.size()-1);
        Node *node = heap.back();
        heap.pop_back();
        nodePositionInHeap.erase(node->id);
        siftDown(0,heap.size()-1,heap);
        return node;
    }
    void insert(Node *node) {
        heap.push_back(node);
        nodePositionInHeap[node->id]=heap.size()-1;
        siftUp(heap.size()-1);
    }
    void swap(int i, int j) {
        nodePositionInHeap[heap[i]->id]=j;
        nodePositionInHeap[heap[j]->id]=i;
        auto temp = heap[i];
        heap[i]=heap[j];
        heap[j]=temp;
    }
    bool containsNode(Node *node) {
        return nodePositionInHeap.find(node->id)!=nodePositionInHeap.end();
    }
    void update(Node *node) {
        siftUp(nodePositionInHeap[node->id]);
    }
};

vector<vector<Node*>> initializeNodes(vector<vector<int>> graph) {
    vector<vector<Node*>> nodes;
    for(int i=0;i<graph.size();i++) {
        nodes.push_back(vector<Node*>{});
        for(int j=0;j<graph[i].size();j++)
            nodes[i].push_back(new Node(i,j,graph[i][j]));
    }
    return nodes;
}

int getManhattanDistance(Node* curNode,Node* endNode) {
    return abs(endNode->row-curNode->row)+abs(endNode->col-curNode->col);
}

vector<Node *> getNeighbouringNodes(Node *node,vector<vector<Node *>> &nodes) {
    vector<Node *> neighbours;
    int numRows = nodes.size();
    int numCols = nodes[0].size();
    int row = node->row;
    int col = node->col;
    if(row<numRows-1)
        neighbours.push_back(nodes[row+1][col]);
    if(row>0)
        neighbours.push_back(nodes[row-1][col]);
    if(col<numCols-1)
        neighbours.push_back(nodes[row][col+1]);
    if(col>0)
        neighbours.push_back(nodes[row][col-1]);
    return neighbours;
}

vector<vector<int>> reconstructPath(Node *endNode) {
    if(endNode->cameFrom==NULL)
        return vector<vector<int>>{};
    vector<vector<int>> path;
    Node *currentNode = endNode;
    while(currentNode!=NULL) {
        path.push_back(vector<int>{currentNode->row,currentNode->col});
        currentNode=currentNode->cameFrom;
    }
    reverse(path.begin(),path.end());
    return path;
}

vector<vector<int>> aStarAlgorithm(int startRow,int startCol,int endRow,int endCol,vector<vector<int>> graph) {
    vector<vector<Node*>> nodes = initializeNodes(graph);
    Node* startNode = nodes[startRow][startCol];
    Node* endNode = nodes[endRow][endCol];
    startNode->distanceFromStart=0;
    startNode->estimatedDistanceToEnd=getManhattanDistance(startNode,endNode);

    MinHeap nodesToVisit(vector<Node *>{startNode});
    while(!nodesToVisit.isEmpty()) {
        Node *currentMinDistanceNode = nodesToVisit.remove();
        if(currentMinDistanceNode==endNode)
            break;
        vector<Node *> neighbours = getNeighbouringNodes(currentMinDistanceNode,nodes);
        for(auto neighbour:neighbours) {
            if(neighbour->value==1)
                continue;
            int tentativeDistanceToNeighbour =currentMinDistanceNode->distanceFromStart+1;
            if(tentativeDistanceToNeighbour>=neighbour->distanceFromStart)
                continue;
            neighbour->cameFrom=currentMinDistanceNode;
            neighbour->distanceFromStart=tentativeDistanceToNeighbour;
            neighbour->estimatedDistanceToEnd=tentativeDistanceToNeighbour+getManhattanDistance(neighbour,endNode);
            if(!nodesToVisit.containsNode(neighbour))
                nodesToVisit.insert(neighbour);
            else
                nodesToVisit.update(neighbour);
        }
    }
    return reconstructPath(endNode);
}


int main() {
    vector<vector<int>> graph = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };
    int startRow=0;
    int startCol=1;
    int endRow=4;
    int endCol=3;
    vector<vector<int>> result = aStarAlgorithm(startRow,startCol,endRow,endCol,graph);
    for(auto x:result)
        cout<<"["<<x[0]<<","<<x[1]<<"]"<<endl;
    return 0;
}