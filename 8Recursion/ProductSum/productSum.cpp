#include <bits/stdc++.h>
using namespace std;

int productSum(vector<any> array, int depth=1) {
    int sum=0;
    for(auto ele : array) {
        if(ele.type()==typeid(vector<any>))
            sum+=productSum(any_cast<vector<any>>(ele),depth+1);
        else
            sum+=any_cast<int>(ele);
    }
    return sum*depth;
}

int main() {
    vector<any> test = {5, 2, vector<any>{7, -1}, 3,vector<any>{6, vector<any>{-13, 8}, 4}};
    cout<<(productSum(test) == 12);
    return 0;
}