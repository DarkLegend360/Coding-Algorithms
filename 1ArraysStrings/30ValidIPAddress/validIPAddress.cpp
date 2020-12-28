#include <bits/stdc++.h>
using namespace std;

bool isValidPart(string st) {
    if(stoi(st)>255)
        return false;
    return st.size()==to_string(stoi(st)).size();
}

string buildIpAddress(vector<string> st) {
    string result;
    for(int i=0;i<st.size();i++) {
        result+=st[i];
        if(i!=st.size()-1)
            result+=".";
    }
    return result;
}

vector<string> validIPAddresses(string st) {
    vector<string> ipAddresses;
    for(int i=1;i<min((int)st.size(),4);i++) {
        vector<string> currentIpAddress(4,"");
        currentIpAddress[0]=st.substr(0,i);
        if(!isValidPart(currentIpAddress[0]))
            continue;
        for(int j=i+1;j<min((int)st.size(),i+4);j++) {
            currentIpAddress[1]=st.substr(i,j-i);
            if(!isValidPart(currentIpAddress[1]))
                continue;
            for(int k=j+1;k<min((int)st.size(),j+4);k++) {
                currentIpAddress[2]=st.substr(j,k-j);
                currentIpAddress[3]=st.substr(k);
                if(!isValidPart(currentIpAddress[2]) || !isValidPart(currentIpAddress[3]))
                    continue;
                ipAddresses.push_back(buildIpAddress(currentIpAddress));
            }
        }
    }
    return ipAddresses;
}

int main() {
    string st = "1921680";
    for(auto x: validIPAddresses(st))
        cout<<x<<endl;
    return 0;
}