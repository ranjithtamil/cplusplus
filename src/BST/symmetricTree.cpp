/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
    //Iterative
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) {                                                                          //  1. if root is NULL, return true;
            return true;
        }
        if((root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL)) {//2. if either(root->l=NULL, root->r!=NULL) OR (root->r=NULL, root->l!=NULL) 
            return false;
        }
        queue<TreeNode*> Q;
        Q.push(root->left);
        Q.push(root->right);
        
        while(!Q.empty()) {
            TreeNode* X=Q.front();
            Q.pop();
            TreeNode* Y=Q.front();
            Q.pop();
            if(X==NULL && Y==NULL) {                                                            //3. IMPORTANT: Continue.... because it can be true
                continue;
            }
            if((X==NULL && Y!=NULL)||(X!=NULL && Y==NULL)) {                                    //4. return false if either one is NULL/Non-NULL combo
                return false;
            }
            if(X->val != Y->val) {                                                              //5. Values need to be same
                return false;
            }
            Q.push(X->left);                                                                    //6. IMPORTANT: Construct Q to push x->l, y->r, x->r, y->l in this ORDER
            Q.push(Y->right);
            Q.push(X->right);
            Q.push(Y->left);
        }
        return true;                                                                            //7. If all conditions went through it is a symmetric tree
    }
    */
    bool findSymmetry(TreeNode* x, TreeNode* y) {
        if((x==NULL && y!=NULL) || (x!=NULL && y==NULL)) {
            return false;
        }
        if(x==NULL && y==NULL) {
            return true;
        }
        if(x->val != y->val) {
            return false;
        }
        if(x->val == y->val && findSymmetry(x->left,y->right) && findSymmetry(x->right,y->left)) {
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) {
            return true;
        }
        if((root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL)) {
            return false;
        }
        if(root->left == NULL && root->right == NULL) {
            return true;
        }
        if(root->left->val != root->right->val) {
            return false;
        }
        bool ans = findSymmetry(root->left,root->right);
        return ans;
    }
};


//Study all edge cases for recursive.
/*
// isSymmetric function
1. if root is NULL, return true
2. if either (root->left=NULL, root->right is NON-NULL)   OR    (root->left is NON-NULL, root->right=NULL) , then return false
3. if root->left=NULL , root->right=NULL , return true (This is case of tree with only 1 element)
4. if it crosses all (1-3), it means root->left and root->right are Non-NULL. Check for root->left->val==root->right->val (if equal, return true).
5. return findSymmetry(root->left, root->right)



// findSymmetry function(X,Y)
1. if(X==NULL AND Y==NULL), return true
2. if either (X=NULL,Y is NON-NULL) OR (X is NON-NULL, Y is NULL), return false
3. if it crosses (1-2), means X and Y are NON-NULL. Check if(X->val != Y->val), return false;
4. Check: (X->val==Y->val) && findSymmetry(X->left,Y->right) && findSymmetry(X->right,Y->left). if passes, return true.

*/
