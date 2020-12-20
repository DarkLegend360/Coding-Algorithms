#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str) {
    int leftIdx=0;
    int rightIdx=str.size()-1;
    while(leftIdx<rightIdx)
        if(str[leftIdx++]!=str[rightIdx--])
            return false;
    return true;
}

int palindromePartitioningMinCuts(string st) {
    vector<vector<bool>> table(st.size(),vector<bool>(st.size(),false));
    for(int i=0;i<st.size();i++)
        for(int j=i;j<st.size();j++)
            table[i][j]=isPalindrome(st.substr(i,j-i+1));
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