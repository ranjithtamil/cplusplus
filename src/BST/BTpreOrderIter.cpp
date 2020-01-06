
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

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode*> myStack;
    if(root==NULL) {
        return result;
    }
    myStack.push(root);
    while(!(myStack.empty())) {
        TreeNode* temp = myStack.top();
        myStack.pop();
        result.push_back(temp->val);
        if(temp->right) {
            myStack.push(temp->right);
        }
        if(temp->left) {
            myStack.push(temp->left);
        }
    }
    
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
