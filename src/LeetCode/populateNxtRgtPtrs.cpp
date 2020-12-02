/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
//Level Order Method (O(N) - Time, O(N) - Space)
    Node* connect(Node* root) {
        if(root==NULL) {
            return NULL;
        }
        
        queue<Node*> Q;
        Node* curr=root;
        Q.push(curr);
        while(!Q.empty()) {
            int qsiz=Q.size();
            for(int i=0;i<qsiz;i++) {
                Node* curnode=Q.front();
                Q.pop();
                if(curnode->left) {
                    Q.push(curnode->left);
                }
                if(curnode->right) {
                    Q.push(curnode->right);
                }
                if(i==qsiz-1) {
                    curnode->next=NULL;
                }
                else {
                    Node* nextnode=Q.front();
                    //Q.pop();                  //SHOULD NOT POP THIS ONE. BECAUSE ITS NOT PROCESSED YET.
                    curnode->next=nextnode;
                }
            }
        }
        return curr;
    }
};
