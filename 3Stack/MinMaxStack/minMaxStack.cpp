#include <bits/stdc++.h>
using namespace std;
class MinMaxStack {
public:
    vector<vector<int>> st;
    int peek() {
        return st[st.size()-1][0];
    }

    int pop() {
        int popVal = st[st.size()-1][0];
        st.pop_back();
        return popVal;
    }

    void push(int number) {
        int maxVal = number;
        if(st.size())
            maxVal=max(number,st[st.size()-1][1]);
        int minVal = number;
        if(st.size())
            minVal=min(number,st[st.size()-1][2]);
        st.push_back({number,maxVal,minVal});
    }

    int getMin() {
        return st[st.size()-1][2];
    }

    int getMax() {
        return st[st.size()-1][1];
    }
};


int main() {
    return 0;
}