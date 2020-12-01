/*Use this example to understand:
                                      1
                                 2        3
                              4     5
                                  6    7
                                      8  
                                     9
*/                                   
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
    void postOrderIter1(TreeNode* root, vector<int>& result) {
        if(root==NULL) {
            return;
        }
        stack<TreeNode*> myStack;
        
        while(root || !myStack.empty()) {           
            while(root) {                                     // add right Node to stack, add center node to stack, then keep going left until you hit NULL
                if(root->right) {                             //contd. So keep in mind that right subtrees(in case you hit left node=NULL) may not have been added to stack
                    myStack.push(root->right);
                }
                myStack.push(root);
                root=root->left;
            }
            
            root = myStack.top();
            myStack.pop();
    //This is the case where current node(root) is a center node, and it's right element is the top of stack. So you should swap current node with top of stack.
    //By swapping, you actually add the center node to stack, and pop the right node out of stack. But now, the root will be the right element as it
    //enters the main while loop- So you can process the right subtree (if exists), and add to stack.
            if(!myStack.empty() && root->right == myStack.top()) {  //!myStack.empty() is Important. in the input test case: [1,null,2,3] it can be empty
                //swap root and stack's top
                TreeNode* temp = myStack.top();
                myStack.pop();
                myStack.push(root);
                root=temp;
            }
            else {                                  //This is the case where the current node(root) is left most node. Set root to NULL after adding to result.
                result.push_back(root->val);
                root=NULL;
            }
        }
        return;
    }
    /*
    void postOrderIter(TreeNode* root, vector<int>&result) {
        if(root == NULL) {
            return;
        }
        stack<TreeNode*> myStack;
        myStack.push(root);
        while(!myStack.empty()) {
            TreeNode* curr = myStack.top();
            myStack.pop();
            result.push_back(curr->val);
            if(curr->left) {
                myStack.push(curr->left);
            }
            if(curr->right) {
                myStack.push(curr->right);
            }
        }
        
        for(int i=0,j=result.size()-1;i<(result.size())/2;i++,j--) {
            int temp = result[i];
            result[i]=result[j];
            result[j]=temp;
        }
    }*/
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        //postOrderIter(root,result);
        postOrderIter1(root,result);
        return result;
    }
};
