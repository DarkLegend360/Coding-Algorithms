#include <bits/stdc++.h>
using namespace std;

void helper(string phoneNumber, int curIdx, int endIdx, vector<string> &possibleStrings, string build, unordered_map<char,vector<char>> map){
    if(curIdx==endIdx) {
        possibleStrings.push_back(build);
        return;
    }
    char currentNum=phoneNumber[curIdx];
    for(auto entry : map[currentNum])
        helper(phoneNumber, curIdx+1, endIdx, possibleStrings, build+entry, map);
}

vector<string> phoneNumberMnemonics(string phoneNumber) {
  vector<string> possibleStrings;
  unordered_map<char,vector<char>> map={
      {'0', {'0'}},
      {'1', {'1'}},
      {'2', {'a','b','c',}},
      {'3', {'d','e','f'}},
      {'4', {'g','h','i'}},
      {'5', {'j','k','l'}},
      {'6', {'m','n','o'}},
      {'7', {'p','q','r','s'}},
      {'8', {'t','u','v'}},
      {'9', {'w','x','y','z'}}
  };
  helper(phoneNumber, 0, phoneNumber.size(), possibleStrings, "", map);
  return possibleStrings;
}

int main() {
string phoneNumber = "1905";
      vector<string> expected = {
    "1w0j",
    "1w0k",
    "1w0l",
    "1x0j",
    "1x0k",
    "1x0l",
    "1y0j",
    "1y0k",
    "1y0l",
    "1z0j",
    "1z0k",
    "1z0l"
      };
      auto actual = phoneNumberMnemonics(phoneNumber);
      cout<<(expected == actual)<<endl;
    return 0;
}