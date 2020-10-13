#include <unordered_map>
using namespace std;

class TrieNode {
public:
  unordered_map<char, TrieNode *> children;
};

class SuffixTrie {
public:
    TrieNode *root;
    char endSymbol;
    SuffixTrie(string str) {
        this->root = new TrieNode();
        this->endSymbol = '*';
        this->populateSuffixTrieFrom(str);
    }
    void insertSubstringStartingAt(int i,string str) {
        TrieNode *node = this->root;
        for(int j=i;j<str.size();j++) {
            char letter = str[j];
            if(node->children.find(letter)==node->children.end())
                node->children.insert({letter,new TrieNode()});
            node=node->children[letter];
        }
        node->children.insert({this->endSymbol,NULL});
    }

    void populateSuffixTrieFrom(string str) {
        for(int i=0;i<str.size();i++)
            this->insertSubstringStartingAt(i,str);
    }

    bool contains(string str) {
        TrieNode *node=this->root;
        for(char letter:str) {
            if(node->children.find(letter)==node->children.end())
                return false;
            node=node->children[letter];
        }
        return node->children.find(this->endSymbol) != node->children.end();
    }
};
