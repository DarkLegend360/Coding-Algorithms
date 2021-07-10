#include <bits/stdc++.h>
using namespace std;

string removeSpaces(string str) {
    int leftIdx=0;
    int rightIdx=0;
    bool spaceFound=false;
    while(rightIdx<str.size() && str[rightIdx]==' ')
        rightIdx++;
    while(rightIdx<str.size()) {
        if(str[rightIdx]==' ') {
            if(!spaceFound) {
                str[leftIdx++]=' ';
                spaceFound=true;
            }
            rightIdx++;
        } else if(str[rightIdx]!=' ') {
            if((str[rightIdx]=='.' && (leftIdx-1)>=0 && str[leftIdx-1]==' ')) 
                str[leftIdx-1]=str[rightIdx++];
            else 
                str[leftIdx++]=str[rightIdx++];
            spaceFound=false;
        }
    }
    str.erase(str.begin()+leftIdx-1,str.end());
    return str;
}

int main() {
    string input = "   Hello Geeks . Welcome   to  GeeksforGeeks   .    ";
    string output = "Hello Geeks. Welcome to GeeksforGeeks.";
    cout<<removeSpaces(input)<<endl;
    cout<<(removeSpaces(input)==output)<<endl;
    return 0;
}