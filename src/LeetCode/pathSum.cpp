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
    void checkSum(TreeNode* root, int cur, bool &found) {
        if(root->left==NULL && root->right==NULL && cur==0) {
            found=true;
            return;
        }
        if(root->left) {
            checkSum(root->left, cur-(root->left->val),found);
        }
        if(root->right) {
            checkSum(root->right, cur-(root->right->val), found);
        }
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL && sum==0) {
            return false;
        }
        if(root==NULL && sum!=0) {
            return false;
        }
        bool found=false;
        checkSum(root,sum - root->val,found);
        return found;
    }
};
