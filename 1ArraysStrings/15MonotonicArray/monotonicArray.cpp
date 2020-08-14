#include <bits/stdc++.h>
using namespace std;

bool isMonotonic(vector<int> &arr) {
	bool inc=true;
	bool dec=true;
	for(int i=1;i<arr.size();i++) {
		if(arr[i-1]>arr[i])
			inc=false;
		if(arr[i-1]<arr[i])
			dec=false;
    }
	return inc||dec;
}

int main() {
    vector<int> arr = {-1, -5, -10, -1100, -1100, -1101, -1102, -9001};
    cout<<(isMonotonic(arr)?"Valid":"Invalid")<<endl;
    return 0;
}