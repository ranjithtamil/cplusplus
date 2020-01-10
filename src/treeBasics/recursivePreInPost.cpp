#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class TreeNode {
  public:
    int val;
    TreeNode* left;
    TreeNode* right;
 
    TreeNode(int x) {
      val=x;
      left=NULL;
      right=NULL;
    }
};

void preOrder(TreeNode* root, vector<int>& result) {
  if(root!=NULL) {
    result.push_back(root->val);
    preOrder(root->left, result);
    preOrder(root->right, result);
  }
}

void inOrder(TreeNode* root, vector<int>& result) {
  if(root!=NULL) {
    inOrder(root->left, result);
    result.push_back(root->val);
    inOrder(root->right, result);
  }
}

void postOrder(TreeNode* root, vector<int>& result) {
  if(root!=NULL) {
    postOrder(root->left, result);
    postOrder(root->right, result);
    result.push_back(root->val);
  }
}

void printResult(vector<int>& result) {
  for(int i=0;i<result.size();i++) {
    cout<<" "<<result.at(i);
  }
}
int main() {
  TreeNode* root=new TreeNode(1);
  root->left=new TreeNode(2);
  root->right=new TreeNode(4);
  vector<int> preOrderResult;
  vector<int> inOrderResult;
  vector<int> postOrderResult;

  cout<<"\nPreOrder Results\n";
  preOrder(root,preOrderResult);
  printResult(preOrderResult);

  cout<<"\nInOrder Results\n";
  inOrder(root,inOrderResult);
  printResult(inOrderResult);

  cout<<"\nPostOrder Results\n";
  postOrder(root,postOrderResult);
  printResult(postOrderResult);

  return 0;
}
