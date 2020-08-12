#include <bits/stdc++.h>
using namespace std;


void shiftUpdate(vector<int> &res,int idx,int &num) {
    for(int i=0;i<=idx;i++)
        if(i==idx)
            res[i]=num;
        else
            res[i]=res[i+1];
}

vector<int> findThreeLargest(vector<int> &arr) {
    vector<int> res(3,INT_MIN);
    for(auto num:arr) {
        if(num>res[2])
            shiftUpdate(res,2,num);
        else if(num>res[1])
            shiftUpdate(res,1,num);
        else if(num>res[0])
            shiftUpdate(res,0,num);
    }
    return res;
}

int main() {
    vector<int> arr ={141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7};
    for(auto x:findThreeLargest(arr))
        cout<<x<<endl;
    return 0;
}