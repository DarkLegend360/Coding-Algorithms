#include <bits/stdc++.h>
using namespace std;

bool isValidSubsequence(vector<int> &array, vector<int> &sequence) {
  int idx=0;
	for(int i=0;i<array.size();i++) {
		if(array[i]==sequence[idx])
			idx++;
	}
	return idx==sequence.size();
}

int main() {
    vector<int> arr={5, 1, 22, 25, 6, -1, 8, 10};
    vector<int> seq={1, 6, -1, 10};
    cout<<(isValidSubsequence(arr,seq)?"Valid":"Invalid")<<endl;
    return 0;
}