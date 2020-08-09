#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
int main() {
    //ios_base::sync_with_stdio(false);
    string S,T;
    getline(cin,T);
    cin>>S;
    int sLen=S.size();
    long long res=0;
    long long tLen = T.size();
    unordered_map<char,int> mp;
    for(int i=0;i<sLen;i++)
        mp[S[i]]=i+1;
    long long i=0;
    string tx,tmp;
    bool flag;
    while(i<tLen) {
        flag=false;
        if(mp.find(T[i])!=mp.end()) {
            int j=2;
            if(i<=tLen-sLen) {
                tx=T.substr(i,sLen);
                tmp=S.substr(0,j);
                if(tmp.size()>=2 && tx[0]==tmp[0] && tx[1]==tmp[1]) {
                    while(tx.find(tmp)!=string::npos) {
                        if(tmp.size()>=2)
                            flag=true;
                        tmp=S.substr(0,++j);
                        if(j>sLen)
                            break;
                    }
                }
            }
            if(flag==true) {
                if(j>=sLen) {
                    res+=1;
                    i+=j;
                }
                else{
                    res+=sLen-j+1;
                    i+=j-1;
                }
                
            } else {
                    if(mp[T[i]]>1 && mp[T[i]]<tLen)
                        res+=3+(sLen-mp[T[i]])+(mp[T[i]]-1);
                    else if(mp[T[i]]==1)
                        res+=sLen;
                    else
                        res+=2+sLen;
            }
        }
        if(!flag)
            i++;
    }
    cout<<res;
}