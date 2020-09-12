#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> arr = {
        {1,3,4,10},
        {2,5,9,11},
        {6,8,12,15},
        {7,13,14,16}
    };
    int row=0;
    int col=0;
    int rowEnd=arr.size()-1;
    int colEnd=arr[0].size()-1;
    int isGoingDown=true;
    while((row >=0 && row<=rowEnd) && (col >=0 && col<=colEnd)) {
        cout<<arr[row][col]<<" ";
        if(isGoingDown) {
            if(col==0 || row==rowEnd) {
                isGoingDown=false;
                if(row==rowEnd)
                    col++;
                else
                    row++;
            } else {
                row++;
                col--;
            }
        } else {
            if(row==0||col==colEnd) {
                isGoingDown=true;
                if(col==colEnd)
                    row++;
                else
                    col++;
            } else {
                row--;
                col++;
            }
        }
    }
    cout<<endl;
    return 0;
}