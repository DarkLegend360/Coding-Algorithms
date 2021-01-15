#include <bits/stdc++.h>
using namespace std;

vector<int> sunsetViews(vector<int> buildings, string direction) {
    vector<int> result;
    if(buildings.size()==0)
        return result;
    int maxHeight=-1;
    if(direction=="EAST") {
        for(int i=buildings.size()-1;i>=0;i--) {
            if(buildings[i]>maxHeight)
                result.insert(result.begin(),i);
            maxHeight=max(maxHeight,buildings[i]);
        }
    } else {
        for(int i=0;i<buildings.size();i++) {
            if(buildings[i]>maxHeight)
                result.push_back(i);
            maxHeight=max(maxHeight,buildings[i]);
        }
    }
    return result;
}

int main() {
    vector<int> buildings = {3, 5, 4, 4, 3, 1, 3, 2};
    string direction = "EAST";
    vector<int> expected = {1, 3, 6, 7};
    vector<int> actual = sunsetViews(buildings, direction);
    for(auto x:actual)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}