#include <iostream>
using namespace std;
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
};

void preOrder(TreeNode* root) {
  if(root!=NULL) {
    cout<<" "<<root->val;
    preOrder(root->left);
    preOrder(root->right);
  }
}

int main() {
  struct TreeNode* root=new TreeNode();
  root->val=1;
  root->left=new TreeNode();
  root->left->val=2;
  root->right=new TreeNode();
  root->right->val=3;

  preOrder(root);
  
//  std::cout << "Hello World!\n";
  return 0;
}
