#include <bits/stdc++.h>
using namespace std;
class TreeNode {
    public:
    int value;
    TreeNode *left,*right;
    TreeNode(int val) {
        value=val;
    }
};

void getResult(TreeNode *root,vector<vector<int>> &res) {
    deque<TreeNode*> q;
    stack<TreeNode*> s;
    vector<int> temp;
    TreeNode* ptr;
    q.push_back(root);
    int level=0;
    while(!q.empty()) {
        temp.clear();
        int n=q.size();
        if(level%2==0) {
            for(int i=0;i<n;i++) {
                ptr=q.front();
                q.pop_front();
                temp.push_back(ptr->value);
                if(ptr->left)
                    q.push_back(ptr->left);
                if(ptr->right)
                    q.push_back(ptr->right);
            }
        } else {
            for(int i=0;i<n;i++) {
                ptr=q.back();
                q.pop_back();
                temp.push_back(ptr->value);
                if(ptr->right)
                    s.push(ptr->right);
                if(ptr->left)
                    s.push(ptr->left);
            }
            while(!s.empty()) {
                q.push_front(s.top());
                s.pop();
            }
        }
        level++;
        res.push_back(temp);
    }
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right =new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);

    vector<vector<int>> res;
    getResult(root,res);
    for(auto x:res) {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}