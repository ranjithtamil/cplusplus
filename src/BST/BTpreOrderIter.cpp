
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
