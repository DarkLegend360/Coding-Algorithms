#include <bits/stdc++.h>
using namespace std;

//Time N^2 and Space N^2
bool sameBsts(vector<int> arrOne, vector<int> arrTwo) {
    if(arrOne.size()==0 && arrTwo.size()==0)
        return true;
    if(arrOne.size()!=arrTwo.size())
        return false;
    if(arrOne[0]!=arrTwo[0])
        return false;
    vector<int> smaller1,larger1;
    vector<int> smaller2,larger2;
    for(int i=1;i<arrOne.size();i++)
        if(arrOne[i]>=arrOne[0])
            larger1.push_back(arrOne[i]);
        else
            smaller1.push_back(arrOne[i]);
    for(int i=1;i<arrTwo.size();i++)
        if(arrTwo[i]>=arrTwo[0])
            larger2.push_back(arrTwo[i]);
        else
            smaller2.push_back(arrTwo[i]);
    return sameBsts(smaller1,smaller2) && sameBsts(larger1,larger2);
}

//Time N^2 and Space (depth)

int getIdxOfFirstSmaller(vector<int> arr, int startingIdx, int minValue) {
    for(int i=startingIdx+1;i<arr.size();i++)
        if(arr[i]<arr[startingIdx] && arr[i]>=minValue)
            return i;
    return -1;
}

int getIdxOfFirstLargerOrEqual(vector<int> arr, int startingIdx, int maxValue) {
    for(int i=startingIdx+1;i<arr.size();i++)
        if(arr[i]>=arr[startingIdx] && arr[i]<maxValue)
            return i;
    return -1;
}


bool areSameBST(vector<int> arrOne,vector<int> arrTwo,int rootIdxOne, int rootIdxTwo, int minValue, int maxValue) {
    if(rootIdxOne==-1 || rootIdxTwo==-1)
        return rootIdxOne==rootIdxTwo;
    if(arrOne[rootIdxOne]!=arrTwo[rootIdxTwo])
        return false;

    int leftRootIdxOne = getIdxOfFirstSmaller(arrOne,rootIdxOne,minValue);
    int leftRootIdxTwo = getIdxOfFirstSmaller(arrTwo,rootIdxTwo,minValue);
    int rightRootIdxOne = getIdxOfFirstLargerOrEqual(arrOne,rootIdxOne,maxValue);
    int rightRootIdxTwo = getIdxOfFirstLargerOrEqual(arrTwo,rootIdxTwo,maxValue);

    bool leftAreSame = areSameBST(arrOne,arrTwo,leftRootIdxOne,leftRootIdxTwo,minValue,arrOne[rootIdxOne]);
    bool rightAreSame = areSameBST(arrOne,arrTwo,rightRootIdxOne,rightRootIdxTwo,arrOne[rootIdxOne],maxValue);
    return leftAreSame && rightAreSame;
}

int main() {
    vector<int> arrOne = {10, 15, 8, 12, 94, 81, 5, 2, 11};
    vector<int> arrTwo = {10, 8, 5, 15, 2, 12, 11, 94, 81};
    //cout<<sameBsts(arrOne,arrTwo)<<endl;
    cout<<areSameBST(arrOne,arrTwo,0,0,INT_MIN,INT_MAX)<<endl;
    return 0;
}