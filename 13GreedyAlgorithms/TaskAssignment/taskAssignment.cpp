#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int element;
    int index;
    Node(int element, int index) {
        this->element=element;
        this->index=index;
    }
};

bool comp(Node a, Node b) {
    return a.element<b.element;
}

vector<vector<int>> taskAssignment(int k, vector<int> tasks) {
	vector<Node> list;
    for(int i=0;i<tasks.size();i++)
        list.push_back(Node(tasks[i],i));
    sort(list.begin(), list.end(), comp);
    int leftIdx=0;
    int rightIdx=list.size()-1;
    vector<vector<int>> result;
    while (leftIdx<rightIdx)
        result.push_back({list[leftIdx++].index,list[rightIdx--].index});
    return result;
}


int main() {
    int k = 3;
    vector<int> tasks = {1, 3, 5, 3, 1, 4};
    vector<vector<int>> expected = {{4, 2}, {0, 5}, {3, 1}};
    auto actual = taskAssignment(k, tasks);
    for(auto x : actual)
        cout<<x[0]<<" "<<x[1]<<endl;
    cout<<(expected == actual)<<endl;
}