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
    //DFS Solution
    int maximum(int a, int b) {
        if(a>b) {
            return a;
        }
        return b;
    }
    int maxDepth(TreeNode* root) {
        vector<pair<int,TreeNode*>> myStack;
        
        if(root==NULL) {
            return 0;
        }
        
        
        pair<int, TreeNode*> rootPair=make_pair(1,root); //also rootPair.first=1; rootPair.second=root;
        myStack.push_back(rootPair);
         
        int maxDepth=0;
        
        while(!(myStack.empty())) {
            pair<int,TreeNode*> myPair = myStack.back();
            
            int currDepth=myPair.first;
            TreeNode* currNode=myPair.second;
            
            maxDepth=maximum(currDepth, maxDepth);
            myStack.pop_back();
            
            if(currNode->left) {
                pair<int,TreeNode*> myPairLeft = make_pair(currDepth+1,currNode->left);
                myStack.push_back(myPairLeft);
            }
            
            if(currNode->right) {
                pair<int,TreeNode*> myPairRight = make_pair(currDepth+1,currNode->right);
                myStack.push_back(myPairRight);
            }
            
            
            
        }
        
        return maxDepth;
    }
    
    /*
    //BFS Solution
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        
        if(root==NULL) {
            return 0;
        }
        q.push(root);
        int depth=0;
        while(!(q.empty())) {
            int n=q.size();
            depth++;
            for(int i=0;i<n;i++) {   
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }    
            }
        }
        
        return depth;
    }
    */
};
