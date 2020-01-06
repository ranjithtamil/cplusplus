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
