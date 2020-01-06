
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
