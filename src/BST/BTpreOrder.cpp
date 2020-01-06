#include <iostream>
#include <bits/stdc++.h>
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
void recurPreOrder(TreeNode* root, vector<int>& result) {
  if(root==NULL) {
    return;
  }
  else {
    result.push_back(root->val);
    recurPreOrder(root->left,result);
    recurPreOrder(root->right,result);
  }
}
vector<int> preOrderTraversal(TreeNode *root) {
  vector<int> result;
  recurPreOrder(root,result);
  return result;
}
int main() {
  vector<int> preOrder;
  TreeNode* root=new TreeNode(1);
  root->right=new TreeNode(2);
  root->right->left=new TreeNode(3);  
  preOrder=preOrderTraversal(root);

  for(int i=0;i<preOrder.size();i++) {
    cout<<" " <<preOrder[i];
  }
  cout<<"\n\n";
  return 0;
  //std::cout << "Hello World!\n";
}
