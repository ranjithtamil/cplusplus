vector<vector<int>> levelOrder(TreeNode* root) {
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
