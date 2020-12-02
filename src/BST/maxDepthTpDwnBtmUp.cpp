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
    int maximum(int a,int b,int c) {
        if(a >= b && a >= c) {
            return a;
        }
        else if(b >= a && b >= c) {
            return b;
        }
        else {
            return c;
        }
    }
    //Top-Down Approach - start from initializing level0, and then add 1 to left and right subchild
    int maximumDepthTopDown(TreeNode* root, int start) {
        int LANS=start;
        int RANS=start;
        if(root->left) {
            LANS = maximumDepthTopDown(root->left,start+1);
        }
        if(root->right) {
            RANS = maximumDepthTopDown(root->right,start+1);
        }
        return maximum(LANS,RANS,start);
    }
    //Bottom-Up Approach - go all the way to leaf node, init leaf node level=0, 
    //and add +1 to max(left subtree,right subtree), so on all the way to the top.
    int maximumDepthBottomUp(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        int LANS=0;
        int RANS=0;
        if(root->left) {
            LANS=maximumDepthBottomUp(root->left);
        }
        if(root->right) {
            RANS=maximumDepthBottomUp(root->right);
        }
        return (max(LANS,RANS)+1);
    }
    int maxDepth(TreeNode* root) {
        
        if(root==NULL) {
            return 0;
        }
        int start = 1;
        //int result=maximumDepthTopDown(root,start);
        int result = maximumDepthBottomUp(root);
        return result;
    }
};
