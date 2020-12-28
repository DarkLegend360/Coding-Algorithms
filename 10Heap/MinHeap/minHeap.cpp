#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    public:
    vector<int> heap;

    MinHeap(vector<int> vector) { 
        heap = buildHeap(vector); 
    }

    vector<int> buildHeap(vector<int> &vector) {
        int firstParentIdx=(vector.size()/2)-1;
        for(int currentIdx=firstParentIdx;currentIdx>=0;currentIdx--)
            siftDown(currentIdx,vector.size()-1,vector);
        return vector;
    }

    void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
        int leftChildIdx=currentIdx*2+1;
        while(leftChildIdx<=endIdx) {
            int rightChildIdx=currentIdx*2+2<=endIdx?currentIdx*2+2:-1;
            int idxToSwap;
            if(rightChildIdx!=-1 && heap[rightChildIdx]<=heap[leftChildIdx])
                idxToSwap=rightChildIdx;
            else
                idxToSwap=leftChildIdx;
            if(heap[idxToSwap]<heap[currentIdx]) {
                swap(heap[idxToSwap],heap[currentIdx]);
                currentIdx=idxToSwap;
                leftChildIdx=currentIdx*2+1;
            } else
                return;
        }
    }

    void siftUp(int currentIdx, vector<int> &heap) {
        int parentIdx=(currentIdx-1)/2;
        while(parentIdx>0 && heap[parentIdx]>heap[currentIdx]) {
            swap(heap[parentIdx],heap[currentIdx]);
            currentIdx=parentIdx;
            parentIdx=(currentIdx-1)/2;
        }
    }

    int peek() {
        return heap[0];
    }

    int remove() {
        swap(heap[0],heap[heap.size()-1]);
        int valueToRemove = heap.back();
        heap.pop_back();
        siftDown(0,heap.size()-1,heap);
        return valueToRemove;
    }

    void insert(int value) {
        heap.push_back(value);
        siftUp(heap.size()-1,heap);
    }
};

bool isMinHeapPropertySatisfied(vector<int> array) {
  for (int currentIdx = 1; currentIdx < array.size(); currentIdx++) {
    int parentIdx = (currentIdx - 1) / 2;
    if (parentIdx < 0) {
      return true;
    }
    if (array[parentIdx] > array[currentIdx]) {
      return false;
    }
  }
  return true;
}


int main() {
    MinHeap minHeap({48, 12, 24, 7, 8, -5, 24, 391, 24, 56, 2, 6, 8, 41});
    minHeap.insert(76);
    cout<<(isMinHeapPropertySatisfied(minHeap.heap));
    cout<<(minHeap.peek() == -5);
    cout<<(minHeap.remove() == -5);
    cout<<(isMinHeapPropertySatisfied(minHeap.heap));
    cout<<(minHeap.peek() == 2);
    cout<<(minHeap.remove() == 2);
    cout<<(isMinHeapPropertySatisfied(minHeap.heap));
    cout<<(minHeap.peek() == 6);
    minHeap.insert(87);
    cout<<(isMinHeapPropertySatisfied(minHeap.heap));
    return 0;
}