#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of distinct integers arr and an array of integer arrays pieces, 
where the integers in pieces are distinct. 
Your goal is to form arr by concatenating the arrays in pieces in any order. 
However, you are not allowed to reorder the integers in each array pieces[i].
Return true if it is possible to form the array arr from pieces. Otherwise, return false.

Example 1:
Input: arr = [85], pieces = [[85]]
Output: true

Example 2:
Input: arr = [15,88], pieces = [[88],[15]]
Output: true
Explanation: Concatenate [15] then [88]

Example 3:
Input: arr = [49,18,16], pieces = [[16,18,49]]
Output: false
Explanation: Even though the numbers match, we cannot reorder pieces[0].

Example 4:
Input: arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
Output: true
Explanation: Concatenate [91] then [4,64] then [78]

Example 5:
Input: arr = [1,3,5,7], pieces = [[2,4,6,8]]
Output: false
*/


bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    unordered_map<int,int> index;
    for(int i=0;i<arr.size();i++)
        index[arr[i]]=i;
    for(auto piece : pieces) {
        int firstPiece = piece[0];
        if(index.find(firstPiece)==index.end())
            return false;
        int firstPieceIdx = index[firstPiece];
        int pieceIdx=0;
        while(pieceIdx<piece.size() && firstPieceIdx<arr.size())
            if(arr[firstPieceIdx++]!=piece[pieceIdx++])
                return false;
        if(pieceIdx!=piece.size())
            return false;
    }
    return true;
}

int main() {
    vector<int> arr = {91,4,64,78};
    vector<vector<int>> pieces = {{78},{4,64},{91}};
    cout<<canFormArray(arr,pieces)<<endl;
    return 0;
}