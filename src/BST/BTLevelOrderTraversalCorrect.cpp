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

    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<vector<int>>result;
        
        if(root==NULL) {
            return result;
        }
        
        Q.push(root);
        
        while(!Q.empty()) {
            int size=Q.size();
            vector<int> op;
            for(int i=0;i<size;i++) {
                TreeNode* curr=Q.front();
                Q.pop();
                op.push_back(curr->val);
                
                if(curr->left) {
                    Q.push(curr->left);
                }
                if(curr->right) {
                    Q.push(curr->right);
                }
            }
            result.push_back(op);
            
        }
        
        
        return result;
      }


int main() {
  vector<vector<int>> levelOrder;
  TreeNode* root=new TreeNode(1);
  root->right=new TreeNode(2);
  root->right->left=new TreeNode(3);  
  levelOrder=levelOrderTraversal(root);

  for(int i=0;i<levelOrder.size();i++) {
    vector<int>temp=levelOrder[i];
          for(int j=0;j<temp.size();j++) {
                  cout<<temp[j]<<" ";
          }
          cout<<"\n";
  }
  cout<<"\n\n";
  return 0;
}
