#include <iostream>
using namespace std;
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) {
    val=x;
    left=NULL;
    right=NULL;
  }
};


void preOrder(TreeNode* root) {
  if(root!=NULL) {
    cout<<" "<<root->val;
    preOrder(root->left);
    preOrder(root->right);
  }
}

int main() {
  struct TreeNode* root=new TreeNode(1);
  root->left=new TreeNode(2);
  root->right=new TreeNode(4);
  preOrder(root);
  return 0;
}
