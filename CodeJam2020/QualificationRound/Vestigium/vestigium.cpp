#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin>>T;
    for(int x=1;x<=T;x++) {
        int N;
        cin>>N;
        vector<vector<int>> arr(N,vector<int>(N,0));
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                cin>>arr[i][j];
        int trace=0,row=0,col=0;
        for(int i=0;i<N;i++)
            trace+=arr[i][i];
        for(int i=0;i<N;i++) {
            unordered_set<int> set;
            for(int j=0;j<N;j++) {
                if(set.find(arr[i][j])!=set.end()) {
                    row++;
                    break;
                } else 
                    set.insert(arr[i][j]);
            }
        }
        for(int i=0;i<N;i++) {
            unordered_set<int> set;
            for(int j=0;j<N;j++) {
                if(set.find(arr[j][i])!=set.end()) {
                    col++;
                    break;
                } else 
                    set.insert(arr[j][i]);
            }
        }
        cout<<"Case #"<<x<<": "<<trace<<" "<<row<<" "<<col<<endl;
    }
    return 0;
}