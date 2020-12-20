#include <bits/stdc++.h>
using namespace std;

int palindromePartitioningMinCuts(string st) {
    vector<vector<bool>> table(st.size(),vector<bool>(st.size(),false));
    for(int i=0;i<st.size();i++)
            table[i][i]=true;
    for(int len=2;len<=st.size();len++) {
        for(int start=0;start<=st.size()-len;start++) {
            int end=start+len-1;
            if(len==2)
                table[start][end]=st[start]==st[end];
            else
                table[start][end]=st[start]==st[end] and table[start+1][end-1];
        }
    }
    vector<int> minCuts(st.size(),INT_MAX);
    for(int i=0;i<st.size();i++) {
        if(table[0][i])
            minCuts[i]=0;
        else {
            for(int j=1;j<=i;j++)
                if(table[j][i])
                    minCuts[i]=min(minCuts[i],minCuts[j-1]+1);
        }
    }
    return minCuts[st.size()-1];
}


int main() {
    string inputString="noonabbad";
    cout<<palindromePartitioningMinCuts(inputString)<<endl;
    return 0;
}