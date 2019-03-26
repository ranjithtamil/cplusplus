
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
    { 
        val=x; 
        left=NULL;
        right=NULL;
    }
   
};

void printNode(TreeNode* n)
    {
        if(n!=NULL)
            cout<<"\nNodeVal= "<<(n->val);
    }
//tree traversal preorder inorder postorder

void preOrder(TreeNode* root)
{
    stack<TreeNode*> treestack;
    while(1)
    {
        while(root)
        {
            printNode(root);
            treestack.push(root);
            root=root->left;
        }
        
        if(treestack.empty())
            break;
        root=treestack.top();
        treestack.pop();
        
        
        
        
        root=root->right;
            
    }
}
void inOrder(TreeNode* root)
{
    stack<TreeNode*> treestack;
    while(1)
    {
        while(root)
        {
            treestack.push(root);
            root=root->left;
        }
        
        if(treestack.empty())
            break;
        
        printNode(treestack.top());
        root=treestack.top();
        treestack.pop();
        root=root->right;
    }
    
}
int main()
{
    //std::cout << "Hello, world!\n";
    
     //std::cout << "Hello, world!\n";
    TreeNode* newn=new TreeNode(10);
    //printNode(newn);
    newn->left=new TreeNode(15);
    newn->left->left=new TreeNode(3);
    newn->left->left->left=new TreeNode(5);
    newn->left->right=new TreeNode(6);
    newn->right=new TreeNode(30);
    newn->right->right=new TreeNode(2);
    newn->right->right->left=new TreeNode(9);
    newn->right->right->right=new TreeNode(8);
    
    
//                               <- 10 -> 
//                     <- 15 ->             30 ->
//                 <- 3        6               <- 2 ->
//                5                           9       8
           
//PreOrder:
//  10,    15,3,5,6,          30,2,9,8  
cout<<"\n\nPrinting Pre-Order traversal\n";                                  
    preOrder(newn);
    
    //InOrder:
//5, 3, 15, 6, 10, 30, 9,2,8    
cout<<"\n\nPrinting In-Order traversal\n";                                  
    inOrder(newn);
    
}
