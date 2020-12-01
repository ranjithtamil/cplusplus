//Refer to Tushar Roy video for explanation: https://www.youtube.com/watch?v=wGXB9OWhPTg

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
    vector<int> inorderTraversal(TreeNode* root) {
        //MORRIS TRAVERSAL
        TreeNode* curr = root;
        vector<int> result;
        
        
        while(curr!=NULL) {
            if(curr->left == NULL) {
                result.push_back(curr->val);
                curr=curr->right;
            }
            else {
                //Find predecessor
                TreeNode* pred;
                pred = curr->left;
                while(pred!=NULL && pred!=curr) {   //might as well be while(1) since youre handling both cases below
                    if(pred->right == NULL) {
                        break;                  //Found right most element of curr's left subtree(i.e., the inorder curr's predecessor)
                    }
                    if(pred->right == curr) {
                        break;                  //Left subtree is visited completely, so go ahead visit curr, and move to right subtree
                    }
                    pred = pred->right;
                }
                
                //Handling both the above cases of predecessor from above
                if(pred->right == NULL) {
                    pred->right = curr; //making the link
                    curr=curr->left;
                }
                else {  //i.e., else if(pred->right == curr)
                    pred->right = NULL;     //Remove link
                    //visit curr
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return result;
    }
};
