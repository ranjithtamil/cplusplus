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
    //space optimized iterative preOrder Traversal
    void preOrderIter1(TreeNode* root, vector<int>& res) {
        stack<TreeNode*> myStack;
        
        if(root==NULL) {
            return;
        }
        
        myStack.push(root);
        while(!myStack.empty()) {
            TreeNode* curr = myStack.top();
            myStack.pop();
            while(curr!=NULL) {
                res.push_back(curr->val);
                if(curr->right) {
                    myStack.push(curr->right);
                }
                curr=curr->left;
            }
        }
        
    }
    void preOrderIter(TreeNode* root, vector<int>& result) {
        stack<TreeNode*> myStack;
        
        if(root==NULL) {
            return;
        }
        
        myStack.push(root);
        
        while(!myStack.empty()) {
            TreeNode* curnode=myStack.top();
            myStack.pop();
            result.push_back(curnode->val);
            if(curnode->right) {
                myStack.push(curnode->right);
            }
            if(curnode->left) {
                myStack.push(curnode->left);
            }
        }
        
    }
    void preOrderRecur(TreeNode* root, vector<int>& result) {
        if(root == NULL) {
            return;
        }
        result.push_back(root->val);
        if(root->left) {
            preOrderRecur(root->left,result);
        }
        if(root->right) {
            preOrderRecur(root->right,result);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        //vector<int> result;
        //preOrderRecur(root,result);
        //preOrderIter(root,result);
        //preOrderIter1(root,result);
        //return result;
        
        
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
                    //visit curr
                    result.push_back(curr->val);
                    curr=curr->left;
                }
                else {  //i.e., else if(pred->right == curr)
                    pred->right = NULL;     //Remove link
                    curr = curr->right;
                }
            }
        }
        return result;
        //END OF MORRIS TRAVERSAL
    }
};
