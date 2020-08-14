#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int value;
    Node *left,*right;
    Node(int val) {
        value=val;
    }
};

void trav(Node *&root,unordered_map<Node*,Node*> &mp)
{
     if(root==NULL) return;
     if(root->left!=NULL) {
         mp[root->left]=root;
         trav(root->left,mp);
     }
     if(root->right!=NULL) {
         mp[root->right]=root;
         trav(root->right,mp);
     }
 }
//BFS method
int main() {
    Node *root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    
    unordered_map<Node*,Node*> mp;
    unordered_set<Node*> st;
    queue<Node*> q;

    Node *start = root->left;//SPECIFY THE SOURCE NODE
    int K=1;//SPECIFY K DISTANCE

    trav(root,mp);
    st.insert(start);
    int level=0;
    q.push(start);
    while(!q.empty()) {
        int len=q.size();
        for(int i=0;i<len;i++) {
            Node *cur = q.front();
            q.pop();
            if(mp.find(cur)!=mp.end() && st.find(mp[cur])==st.end()){
                q.push(mp[cur]);
                st.insert(mp[cur]);
            }
            if(cur->left!=NULL && st.find(cur->left)==st.end()) {
                q.push(cur->left);
                st.insert(cur->left);
            }
            if(cur->right!=NULL && st.find(cur->right)==st.end()){
                q.push(cur->right);
                st.insert(cur->right);
            }
        }
        if(++level==K) {
            while(!q.empty()) {
                cout<<q.front()->value<<endl;
                q.pop();
            }
            return 1;
        }
    }
    return 0;
}

//DFS method
// void helper(Node *root,unordered_map<Node*,Node*> &mp,unordered_set<Node*> &st,vector<int> &res,int K) {
//     if(!root) return;
//     if(st.find(root)!=st.end()) return;
//     st.insert(root);
//     if(K==0) {
//         res.push_back(root->value);
//         return;
//     }
//     helper(root->left,mp,st,res,K-1);
//     helper(root->right,mp,st,res,K-1);
//     if(mp.find(root)!=mp.end())
//         helper(mp[root],mp,st,res,K-1);
// }
    
    
// vector<int> distanceK(Node* root, Node* target, int K) {
//     if(!root) return {};
//     vector<int> res;
//     unordered_map<Node*,Node*> mp;
//     unordered_set<Node*> st;
//     trav(root,mp);
//     helper(target,mp,st,res,K);
//     return res;
// }