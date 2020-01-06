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
 
void inOrderrecur(TreeNode* root, vector<int>&result) {
        if(root!=NULL) {
            inOrderrecur(root->left,result);
            result.push_back(root->val);
            inOrderrecur(root->right,result);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        inOrderrecur(root,result);
        return result;
    }
int main() {
  vector<int> inOrder;
  TreeNode* root=new TreeNode(1);
  root->right=new TreeNode(2);
  root->right->left=new TreeNode(3);  
  inOrder=inOrderTraversal(root);

  for(int i=0;i<inOrder.size();i++) {
    cout<<" " <<inOrder[i];
  }
  cout<<"\n\n";
  return 0;
  //std::cout << "Hello World!\n";
}
