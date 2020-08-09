#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N,K,ele;
    cin>>N>>K;
    priority_queue<long long> heap;
    for(int i=0;i<N;i++) {
        cin>>ele;
        heap.push(ele);
    }
    while(K--) {
        ele=heap.top();
        heap.pop();
        heap.push(ele/2);
    }
    long long sum=0;
    while(!heap.empty()) {
        sum+=heap.top();
        heap.pop();
    }
    cout<<sum;
}