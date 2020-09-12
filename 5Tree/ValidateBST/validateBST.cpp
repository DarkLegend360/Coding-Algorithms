#include <bits/stdc++.h>
using namespace std;
class BST {
    public:
        int value;
        BST *left,*right;
};
bool validateBST(BST *tree,int minVal,int maxVal) {
	if(!tree)
		return true;
	if(tree->value < minVal || tree->value >= maxVal)
		return false;
	return validateBST(tree->left,minVal,tree->value) && validateBST(tree->right,tree->value,maxVal);
}

int main() {

}