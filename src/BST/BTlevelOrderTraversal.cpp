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

vector<vector<int>> levelOrderTraversal(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<vector<int>>result;
        if(root==NULL) {
            return result;
        }
        Q.push(root);
        Q.push(NULL);
        
        vector<int> op;
        
        while(Q.size()>1) {
            
            TreeNode* temp=Q.front();
            Q.pop();
            
            if(temp==NULL) {
                Q.push(NULL);
                result.push_back(op);
                op.clear();
                
            }
            else {    
                if(temp->left) {
                    Q.push(temp->left);
                    
                } 
                if(temp->right) {
                    Q.push(temp->right);
                    
                }    
                op.push_back(temp->val);
            }
            
            
            
        }
        result.push_back(op);
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
  //std::cout << "Hello World!\n";
}
