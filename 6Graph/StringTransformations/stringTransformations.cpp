#include <bits/stdc++.h>
using namespace std;

int distance2(string beginWord, string endWord, vector<string>& wordList) { //Brute Force
    unordered_set<string> wordHash;
    for(auto word : wordList)
        wordHash.insert(word);
    if(wordHash.find(endWord)==wordHash.end())
        return -1;
    unordered_set<string> visited;
    queue<string> myQueue;
    myQueue.push(beginWord);
    visited.insert(beginWord);
    int currentLevel=1;
    while(!myQueue.empty()) {
        int size = myQueue.size();
        for(int i=0;i<size;i++) {
            string currentWord = myQueue.front();
            myQueue.pop();
            for(int j=0;j<currentWord.size();j++) {
                string transformedWord = currentWord;
                for(int k=0;k<wordList.size();k++) {
                    transformedWord[j]=wordList[k][j];
                    if(transformedWord==endWord)
                        return currentLevel;
                    if(wordHash.find(transformedWord)!=wordHash.end() && visited.find(transformedWord)==visited.end()) {
                        myQueue.push(transformedWord);
                        visited.insert(transformedWord);
                    }
                }
            }
        }
        currentLevel++;
    }
    return -1;
}

int distance(string beginWord, string endWord, vector<string>& wordList) { //Optimized
    unordered_map<string, vector<string>> mapping;
    for(auto word : wordList) {
        for(int i=0;i<word.size();i++) {
            string identifier = word.substr(0,i)+"*"+word.substr(i+1);
            if(mapping.find(identifier)==mapping.end())
                mapping[identifier]=vector<string>{word};
            else
                mapping[identifier].push_back(word);
            
        }
    }
    int currentLevel=1;
    queue<string> myQueue;
    unordered_set<string> visited;
    myQueue.push(beginWord);
    visited.insert(beginWord);
    while(!myQueue.empty()) {
        int size = myQueue.size();
        for(int i=0;i<size;i++) {
            string currentWord = myQueue.front();
            myQueue.pop();
            for(int j=0;j<currentWord.size();j++) {
                string identifier = currentWord.substr(0,j)+"*"+currentWord.substr(j+1);
                for(auto word : mapping[identifier]) {
                    if(word==endWord)
                        return currentLevel;
                    if(visited.find(word)==visited.end()) {
                        myQueue.push(word);
                        visited.insert(word);
                    }
                }
            }
        }
        currentLevel++;
    }
    return -1;
}


int main() {
    string beginWord = "dog";
    string endWord = "lot";
    vector<string> words = {"dot", "mot", "lot"};
    cout<<distance(beginWord, endWord, words)<<endl;;
    return 0;
}