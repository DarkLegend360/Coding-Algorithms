#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    string a,b;
    int count=n;
    cin>>a>>b;
    vector<char> Bride(a.begin(),a.end()),Groom(b.begin(),b.end());
    int i=0;
    int flag=n;
    while(i<n) {
        if(Bride[i]==Groom[0]) {
            Groom.erase(Groom.begin());
            flag=Groom.size();
            count--;
            i++;
        } else {
            int x=Groom[0];
            Groom.erase(Groom.begin());
            Groom.push_back(x);
            if(flag--==0) {
                cout<<count<<endl;
                return 0;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}