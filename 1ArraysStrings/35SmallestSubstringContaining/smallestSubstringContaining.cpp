#include <bits/stdc++.h>
using namespace std;

string smallestSubstringContaining(string bigString, string smallString) {
    unordered_map<char,int> charCounts;
    for(auto x : smallString) {
        if(charCounts.find(x)==charCounts.end())
            charCounts[x]=1;
        else
            charCounts[x]++;
    }
    int uniqueChars=charCounts.size();
    int currentUniqueChars=0;
    unordered_map<char,int> currentCharCounts;
    int startIdx=0;
    int minLength=INT_MAX;
    int leftIdx=0;
    int rightIdx=0;
    while(rightIdx<bigString.size()) {
        if(charCounts.find(bigString[rightIdx])==charCounts.end()){
            rightIdx++;
            continue;
        }
        if(currentCharCounts.find(bigString[rightIdx])!=currentCharCounts.end())
            currentCharCounts[bigString[rightIdx]]++;
        else
            currentCharCounts[bigString[rightIdx]]=1;
        if(currentCharCounts[bigString[rightIdx]]==charCounts[bigString[rightIdx]])
            currentUniqueChars++;
        while(currentUniqueChars==uniqueChars && leftIdx<=rightIdx) {
            int length=rightIdx-leftIdx+1;
            if(currentUniqueChars==uniqueChars && length<minLength) {
                startIdx=leftIdx;
                minLength=length;
            }
            if(charCounts.find(bigString[leftIdx])==charCounts.end()){
                leftIdx++;
                continue;
            }
            if(currentCharCounts[bigString[leftIdx]]==charCounts[bigString[leftIdx]])
                currentUniqueChars--;
            currentCharCounts[bigString[leftIdx]]--;
            leftIdx++;
        }
        rightIdx++;
    }
    return minLength==INT_MAX?"":bigString.substr(startIdx,minLength);
}

int main() {
    string bigString = "abcd$ef$axb$c$";
    string smallString = "$$abf";
    string expected = "f$axb$";
    cout<<(smallestSubstringContaining(bigString, smallString) == expected);
    return 0;
}