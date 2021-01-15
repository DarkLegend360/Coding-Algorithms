#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    unordered_map<char,TrieNode *> children;
    string endWord="";
};

class Trie {
    public:
    TrieNode *root;
    char endSymbol;
    Trie() {
        this->root=new TrieNode();
        this->endSymbol='*';
    }
    void addWord(string word) {
        TrieNode *root = this->root;
        for(auto letter:word) {
            if(root->children.find(letter)==root->children.end())
                root->children[letter]=new TrieNode();
            root=root->children[letter];
        }
        root->children[this->endSymbol]=NULL;
        root->endWord=word;
    }
};

vector<vector<int>> getNeighbours(int i, int j, vector<vector<char>> board) {
    vector<vector<int>> neighbours;
    if(i>0)
        neighbours.push_back({i-1,j});
    if(j>0)
        neighbours.push_back({i,j-1});
    if(i<board.size()-1)
        neighbours.push_back({i+1,j});
    if(j<board[0].size()-1)
        neighbours.push_back({i,j+1});
    if(i>0 && j>0)
        neighbours.push_back({i-1,j-1});
    if(i<board.size()-1 && j<board[0].size()-1)
        neighbours.push_back({i+1,j+1});
    if(i>0 && j<board[0].size()-1)
        neighbours.push_back({i-1,j+1});
    if(i<board.size()-1 && j>0)
        neighbours.push_back({i+1,j-1});
    return neighbours;
}

void explore(int i, int j, vector<vector<char>> board, TrieNode *node, vector<vector<bool>> &isVisited, unordered_set<string> &finalWords) {
    if(isVisited[i][j])
        return;
    char letter = board[i][j];
    if(node->children.find(letter)==node->children.end())
        return;
    isVisited[i][j]=true;
    node=node->children[letter];
    if(node->children.find('*')!=node->children.end())
        finalWords.insert(node->endWord);
    vector<vector<int>> neighbours = getNeighbours(i, j, board);
    for(auto neighbour : neighbours)
        explore(neighbour[0], neighbour[1], board, node, isVisited, finalWords);
    isVisited[i][j]=false;
}

vector<string> boggleBoard(vector<vector<char>> board, vector<string> words) {
    Trie trie;
    for(auto word:words)
        trie.addWord(word);
    unordered_set<string> finalWords;
    vector<vector<bool>> isVisited(board.size(),vector<bool>(board[0].size(),false));
    for(int i=0;i<board.size();i++)
        for(int j=0;j<board[0].size();j++)
            explore(i, j, board, trie.root,isVisited, finalWords);
    vector<string> result;
    for(auto word:finalWords)
        result.push_back(word);
    return result;
}

bool contains(vector<string> wordArray, string targetWord) {
    for (string word : wordArray) 
        if (targetWord == word) 
            return true;
    return false;
}

int main() {
    vector<vector<char>> board = {
          {'t', 'h', 'i', 's', 'i', 's', 'a'},
          {'s', 'i', 'm', 'p', 'l', 'e', 'x'},
          {'b', 'x', 'x', 'x', 'x', 'e', 'b'},
          {'x', 'o', 'g', 'g', 'l', 'x', 'o'},
          {'x', 'x', 'x', 'D', 'T', 'r', 'a'},
          {'R', 'E', 'P', 'E', 'A', 'd', 'x'},
          {'x', 'x', 'x', 'x', 'x', 'x', 'x'},
          {'N', 'O', 'T', 'R', 'E', '-', 'P'},
          {'x', 'x', 'D', 'E', 'T', 'A', 'E'},
      };
    vector<string> words = {"this","is","not","a","simple","boggle","board", "test","REPEATED", "NOTRE-PEATED"};
    vector<string> expected = {"this","is","a","simple","boggle","board","NOTRE-PEATED"};
    vector<string> actual = boggleBoard(board, words);
    assert(actual.size() == expected.size());
    for (string word : actual)
        cout<<(contains(expected, word));
    return 0;
}