#include <bits/stdc++.h>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
  int n=matrix.size(),m=matrix[0].size();
	int i=0,j=m-1;
	while(i<n && j>=0) {
		if(matrix[i][j]==target)
			return{i,j};
		else if(matrix[i][j]<target)
			i++;
		else
			j--;
	}
  return {-1,-1};
}

int main() {
    int target = 44;
    vector<vector<int>> arr={{1, 4, 7, 12, 15, 1000},
    {2, 5, 19, 31, 32, 1001},
    {3, 8, 24, 33, 35, 1002},
    {40, 41, 42, 44, 45, 1003},
    {99, 100, 103, 106, 128, 1004}};
    for(auto x:searchInSortedMatrix(arr,target))
        cout<<x<<" ";
    cout<<endl;
    return 0;
}