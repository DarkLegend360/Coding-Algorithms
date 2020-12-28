#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    unordered_map<char,TrieNode *> children;
    string word;
};

class Trie {
    public:
    TrieNode *root;
    char endSymbol;
    Trie() {
        this->root= new TrieNode();
        this->endSymbol='*';
    }
    void insert(string str) {
        TrieNode *currentNode = this->root;
        for(int i=0;i<str.size();i++) {
            char letter = str[i];
            if(currentNode->children.find(letter)==currentNode->children.end())
                currentNode->children.insert({letter,new TrieNode()});
            currentNode=currentNode->children[letter];
        }
        currentNode->children.insert({this->endSymbol,NULL});
        currentNode->word=str;
    }
};

void findSmallStringIn(string bigString, int startIdx, Trie *trie, unordered_set<string> &containedString) {
    TrieNode *currentNode = trie->root;
    for(int idx=startIdx;idx<bigString.size();idx++) {
        if(currentNode->children.find(bigString[idx])==currentNode->children.end())
            break;
        currentNode=currentNode->children[bigString[idx]];
        if(currentNode->children.find(trie->endSymbol)!=currentNode->children.end())
            containedString.insert(currentNode->word);
    }
}

vector<bool> multiStringSearch(string bigString, vector<string> smallStrings) {
    Trie *root = new Trie();
    for(auto smallString : smallStrings)
        root->insert(smallString);
    unordered_set<string> containedString;
    for(int idx=0;idx<bigString.size();idx++)
        findSmallStringIn(bigString,idx,root,containedString);
    vector<bool> results;
    for(auto smallString : smallStrings)
        results.push_back(containedString.find(smallString)!=containedString.end());
    return results;
}

int main() {
    vector<bool> expected{true, false, true, true, false, true, false};
    assert(multiStringSearch("this is a big string",{"this", "yo", "is", "a", "bigger", "string","kappa"}) == expected);
    return 0;
}