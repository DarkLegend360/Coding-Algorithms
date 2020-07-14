#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[]={5, 15, 10, 20, 3};
    priority_queue<double> lower;
    priority_queue<double,vector<double>,greater<double>> higher; 
    for(auto x:arr) {
        if(lower.empty() || x<lower.top())
            lower.push(x);
        else
            higher.push(x);
        int l=lower.size(),h=higher.size();
        if(abs(l-h)>1) {
            if(l>h) {
                higher.push(lower.top());
                lower.pop();
            } else {
                lower.push(higher.top());
                higher.pop();
            }
        }
        if(lower.size()==higher.size())
            cout<<((lower.top()+higher.top())/2.0)<<endl;
        else
            cout<<(lower.size()>higher.size()?lower.top():higher.top())<<endl;
    }
    return 0;
}