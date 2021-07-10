#include <bits/stdc++.h>
using namespace std;

//First Question
int binarySearch(vector<int> a, int target){
	int leftIdx=0;
	int rightIdx=a.size()-1;
	int middleIdx;
	while(leftIdx<rightIdx-1) {
		middleIdx=leftIdx+(rightIdx-leftIdx)/2;
		if(a[middleIdx]==target)
			return middleIdx;
		else if(a[middleIdx]>target)
			rightIdx=middleIdx;
		else
			leftIdx=middleIdx;
	}
	if (target <= a[leftIdx]) 
		return leftIdx;
    if (target > a[leftIdx] && target <= a[rightIdx]) 
    	return rightIdx;
    if (target > a[rightIdx]) 
    	return rightIdx + 1;
    return -1;
}

int boundedSquareSum(vector<int> a, vector<int> b, int lower, int upper) {
	int noOfPairs=0;
	if(a.size()>b.size())
		swap(a, b);
	for(int i=0;i<a.size();i++)
		a[i]*=a[i];
	sort(a.begin(), a.end());
	if(a[0]>upper)
		return noOfPairs;
	for(int i=0;i<b.size();i++) {
		b[i]*=b[i];
		if(b[i]>upper)
			continue;
		int left = binarySearch(a, lower-b[i]);
		int right = binarySearch(a, upper-b[i]);
		noOfPairs+=right-left;
	}
	return noOfPairs;
}

//Second Question
bool isValid(int currentMinTime, int p, vector<int> driver, vector<int> battery) {
	bool flag;
	int batIdx=0;
	for(int driverIdx=0;driverIdx<driver.size();driverIdx++) {
		flag=true;
		while(batIdx<battery.size()) {
			int curDriverTime = abs(driver[driverIdx]-battery[batIdx])+abs(battery[batIdx]-p);
			if(curDriverTime<=currentMinTime) {
				flag=false;
				batIdx++;
				break;
			}
			batIdx++;
		}
		if(flag)
			return false;
	}
	return true;
}
int minimumTimeNeeded(int p, vector<int> driver, vector<int> battery) {
	int minTimeNeeded=0;
	sort(driver.begin(), driver.end());
	sort(battery.begin(), battery.end());
	int leftIdx=0;
	int rightIdx=INT_MAX;
	int middleIdx;
	while(leftIdx<=rightIdx) {
		middleIdx=leftIdx+(rightIdx-leftIdx)/2;
		if(isValid(middleIdx, p, driver, battery))
			rightIdx=middleIdx-1;
		else
			leftIdx=middleIdx+1;
	}
	return leftIdx;
}

//Third Question
int largestRectangleArea(vector<int> heights) {
    if(!heights.size())
        return 0;
    vector<int> lessFromLeft(heights.size()), lessFromRight(heights.size());
    lessFromLeft[0]=-1;
    lessFromRight[heights.size()-1]=heights.size();
    for(int i=1;i<heights.size();i++) {
        int j=i-1;
        while(j>=0 && heights[j]>=heights[i])
            j=lessFromLeft[j];
        lessFromLeft[i]=j;
    }
    for(int i=heights.size()-2;i>=0;i--) {
        int j=i+1;
        while(j<heights.size() && heights[j]>=heights[i])
            j=lessFromRight[j];
        lessFromRight[i]=j;
    }
    vector<int> prefixSum(heights.size());
    prefixSum[0]=0;
    for(int i=1;i<heights.size();i++)
    	prefixSum[i]=prefixSum[i-1]+heights[i];
    int maxArea=0;
    for(int i=0;i<heights.size();i++) {
    	int left = (lessFromLeft[i]==-1)?0:prefixSum[lessFromLeft[i]];
    	int right = (lessFromRight[i]==heights.size())?prefixSum[heights.size()-1]:prefixSum[lessFromRight[i]-1];
        maxArea = max(maxArea, heights[i]*(right-left));
    }
    return maxArea;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//First Question
	cout<<boundedSquareSum({3, -1, 9}, {100, 5, -2}, 7, 99)<<endl;
	//Second Question
	cout<<minimumTimeNeeded(50, {20, 100}, {60, 10, 40, 80})<<endl;
	//Third Question
	cout<<largestRectangleArea({3, 1, 6, 4, 5, 2})<<endl;
	return 0;
}