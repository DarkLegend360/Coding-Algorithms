#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &matrix,int r,int rEnd,int c,int cEnd) {
	for(int i=r;i<=rEnd;i++)
		if(matrix[i][c]!=0 || matrix[i][cEnd]!=0)
			return false;
	for(int i=c;i<=cEnd;i++)
		if(matrix[r][i]!=0 || matrix[rEnd][i]!=0)
			return false;
	return true;
}
//bool
void squareOfZeroes(vector<vector<int>> matrix,int &maxSize) {
	int N=matrix.size();
	for(int i=0;i<N-1;i++)
		for(int j=0;j<N-1;j++)
			for(int k=1;k+i<N && k+j<N;k++)
				if(isValid(matrix,i,i+k,j,j+k))
                    maxSize=max(maxSize,k+1);
                    //return true;
  //return false;
}

int main() {
    vector<vector<int>> arr = {
        {1,1,1,0,1,0},
        {0,0,0,0,0,1},
        {0,1,1,1,0,1},
        {0,0,0,1,0,1},
        {0,1,1,1,0,1},
        {0,0,0,0,0,1}  
    };
    int maxSize=0;
    squareOfZeroes(arr,maxSize);
    cout<<maxSize<<endl;
    //cout<<squareOfZeroes(arr)<<endl;
    return 0;
}