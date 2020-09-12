#include <bits/stdc++.h>
using namespace std;

bool hasSingleCycle(vector<int> array) {
  int visited=0;
	int curIdx=0;
	int arrLength=array.size();
	while(visited<arrLength) {
		if(visited>0 && curIdx==0)
			return false;
		curIdx=(curIdx+array[curIdx])%arrLength;
		if(curIdx<0)
			curIdx+=arrLength;
		visited++;
		curIdx%=arrLength;
	}
	return curIdx==0;
}


int main() {
    vector<int> arr = {2, 3, 1, -4, -4, 2};
    cout<<hasSingleCycle(arr)<<endl;
    return 0;
}