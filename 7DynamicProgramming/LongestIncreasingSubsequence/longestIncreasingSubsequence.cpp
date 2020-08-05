#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr={5,7,-24,12,10,2,3,12,5,6,35};
    int N=arr.size();
    int maxIdx=0;
    vector<int> length(N,1),sequence(N,-1);
    for(int i=1;i<N;i++) {
        for(int j=0;j<i;j++) {
            if(arr[j]<arr[i] && length[j]>=length[i]) {
                length[i]=length[j]+1;
                sequence[i]=j;
            }
        }
        if(length[i]>=length[maxIdx])
            maxIdx=i;
    }
    for(auto x:length)
        cout<<x<<" ";
    cout<<endl;
    for(auto x:sequence)
        cout<<x<<" ";
    cout<<endl;
    cout<<"SEQUENCE BELOW"<<endl;
    while(maxIdx!=-1) {
        cout<<arr[maxIdx]<<" <= ";
        maxIdx=sequence[maxIdx];
    }
    cout<<endl;
    return 0;
}