#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<int>> arr = {
        {1,2,3,4},
        {12,13,14,5},
        {11,16,15,6},
        {10,9,8,7}
    };
    int rowStart=0;
    int rowEnd=arr.size()-1;
    int colStart=0;
    int colEnd=arr[0].size()-1;
    vector<int> res;
    while(rowStart<=rowEnd && colStart <= colEnd) {
        for(int col=colStart;col<=colEnd;col++)
            res.push_back(arr[rowStart][col]);
        rowStart++;
        for(int row=rowStart;row<=rowEnd;row++)
            res.push_back(arr[row][colEnd]);
        colEnd--;
        for(int col=colEnd;col>=colStart;col--){
            if(rowStart>rowEnd)
                    break;
            res.push_back(arr[rowEnd][col]);
		}
        rowEnd--;
        for(int row=rowEnd;row>=rowStart;row--){
			if(colStart>colEnd)
				break;
            res.push_back(arr[row][colStart]);
		}
        colStart++;
    }
    for(auto x:res)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}