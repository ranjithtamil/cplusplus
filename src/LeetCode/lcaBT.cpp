/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isFound(TreeNode* root, int p, int q,TreeNode** LCA) {
        bool mid=false;
        bool lft=false;
        bool rght=false;
        
        if(root->val==p || root->val==q) {          //if current root node is one of p or q values, set mid=True
            mid=true;
        }
        if(root->left!=NULL) {                      //check if left subtree has one of p or q values.
            lft=isFound(root->left,p,q,LCA);
        }
        if(root->right!=NULL) {                     //check if right subtree has one of p or q values.
            rght=isFound(root->right,p,q,LCA);
        }                                           //if either (mid && left) or (mid && right) or (left && right) are true, SET LCA as current node and RETURN TRUE.
        if((mid==true && lft==true)) {              
            *LCA=root;
            return true;
        }
        if(mid==true && rght==true) {
            *LCA=root;
            return true;
        }
        if(lft==true && rght==true) {
            *LCA=root;
            return true;
        }
        if(mid==true) {                           // if p is found in either of left OR right OR mid, DONOT SET LCA, but RETURN TRUE.
            return true;
        }
        if(lft==true) {
            return true;
        }
        if(rght==true) {
            return true;
        }
        return false;                             // return FALSE.
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) {
            return NULL;
        }
        TreeNode* LCA=NULL;
        bool ret = isFound(root,p->val,q->val,&LCA);
        return LCA;
    }
};
