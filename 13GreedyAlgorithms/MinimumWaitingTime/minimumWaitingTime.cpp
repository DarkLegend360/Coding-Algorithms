#include <bits/stdc++.h>
using namespace std;

int minimumWaitingTime(vector<int> queries) {
    sort(queries.begin(), queries.end());
    int minTime=0;
    int curTime=0;
    for (auto query : queries) {
        minTime+=curTime;
        curTime+=query;
    }
    return minTime;
}

int main() {
    vector<int> queries = {3, 2, 1, 2, 6};
    int expected = 17;
    auto actual = minimumWaitingTime(queries);
    cout<<(expected == actual)<<endl;
}