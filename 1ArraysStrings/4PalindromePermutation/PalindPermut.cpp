#include <bits/stdc++.h>
using namespace std;

// bool PalinPermut(string s) {
//     vector<int> arr(128,0);
//     bool flag=false;;
//     for(auto x:s)
//         arr[x]++;
//     for(auto x:arr) {
//         if(x%2!=0) {
//             if(flag)
//                 return false;
//             flag=true;
//         }
//     }
//     return true;
// }

bool PalinPermut(string s) {
    vector<int> arr(128,0);
    int countOdd=0;
    for(auto x:s) {
        arr[x]++;
        if(arr[x]%2!=0)
            countOdd++;
        else
            countOdd--;
    }
    return countOdd<=1;
}

int main() {
    string s;
    cin>>s;
    if(PalinPermut(s))
        cout<<"Valid"<<endl;
    else
        cout<<"Invalid"<<endl;
    return 0;
}