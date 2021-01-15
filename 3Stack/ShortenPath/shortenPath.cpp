#include <bits/stdc++.h>
using namespace std;

string shortenPath(string path) {
    int prevSlashIdx=0;
    vector<string> filter;
    bool isAbsolutePath=path[0]=='/';
    if(!isAbsolutePath)
        prevSlashIdx=-1;
    for(int i=0;i<=path.size();i++) {
        if(path[i]=='/' || i==path.size()) {
            string subString = path.substr(prevSlashIdx+1,max(i-prevSlashIdx-1,0));
            if(!subString.empty() && subString!=".")
                filter.push_back(subString);
            prevSlashIdx=i;
        }
    }
    vector<string> finalFilter;
    for(string token:filter) {
        if(!finalFilter.empty() && token=="..") {
            if(!isAbsolutePath && (finalFilter.empty() || finalFilter.back()=="..")) {
                finalFilter.push_back(token);
                continue;
            }
            finalFilter.pop_back();
        } else if(finalFilter.empty() && isAbsolutePath && token=="..")
            continue;
        else
            finalFilter.push_back(token);
    }
    string finalString;
    if(isAbsolutePath)
        finalString+="/";
    for(int i=0;i<finalFilter.size();i++) {
        if(i==finalFilter.size()-1)
            finalString+=finalFilter[i];
        else
            finalString+=finalFilter[i]+"/";
    }
    return finalString;
}

int main() {
    string expected = "/foo/bar/baz";
    string actual = shortenPath("/foo/../test/../test/../foo//bar/./baz");
    cout<<(expected == actual)<<endl;
    return 0;
}