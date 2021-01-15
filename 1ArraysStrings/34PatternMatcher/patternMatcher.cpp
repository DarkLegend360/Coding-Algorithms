#include <bits/stdc++.h>
using namespace std;

vector<char> getNewPatern(string pattern) {
    vector<char> newPattern(pattern.begin(),pattern.end());
    if(pattern[0]=='x')
        return newPattern;
    for(int i=0;i<pattern.size();i++) {
        if(newPattern[i]=='x')
            newPattern[i]='y';
        else
            newPattern[i]='x';
    }
    return newPattern;
}

int getCountsandFirstYPos(vector<char> &pattern,unordered_map<char,int> &count) {
    int firstY=-1;
    for(int i=0;i<pattern.size();i++) {
        if(pattern[i]=='y' && firstY==-1)
            firstY=i;
        count[pattern[i]]++;
    }
    return firstY;    
}

string getNewString(vector<char> pattern, string x, string y) {
    string newString;
    for(auto ch : pattern)
        if(ch=='x')
            newString+=x;
        else
            newString+=y;
    return newString;
}

vector<string> patternMatcher(string pattern, string str) {
    if(pattern.size()>str.size())
        return vector<string>{};
    auto newPattern=getNewPatern(pattern);
    bool didSwap=pattern[0]!=newPattern[0];
    unordered_map<char,int> counts = {{'x',0},{'y',0}};
    int firstYPos = getCountsandFirstYPos(newPattern,counts);
    if(counts['y']!=0) {
        for(int lenOfX=1;lenOfX<str.size();lenOfX++) {
            int lenOfY=str.size()-(lenOfX*counts['x']);
            if(lenOfY%counts['y']!=0)
                continue;
            lenOfY/=counts['y'];
            if(lenOfY<=0)
                continue;
            int yIdx=firstYPos*lenOfX;
            string x=str.substr(0,lenOfX);
            string y=str.substr(yIdx,lenOfY);
            string newString = getNewString(newPattern,x,y);
            if(str==newString)
                return didSwap?vector<string>{y,x}:vector<string>{x,y};
        }
    } else {
        if(str.size()%counts['x']!=0)
            return vector<string>{};
        int lenOfX=str.size()/counts['x'];
        string x=str.substr(0,lenOfX);
        return didSwap?vector<string>{"",x}:vector<string>{x,""};
    }
    return {};
}

int main() {
    vector<string> expected{"go", "powerranger"};
    cout<<(patternMatcher("xxyxxy", "gogopowerrangergogopowerranger") ==expected);
    return 0;
}