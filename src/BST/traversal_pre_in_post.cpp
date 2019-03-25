//g++  5.4.0

#include <iostream>

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
void PreOrder(TreeNode* root)
{
    if(root==NULL)
        return;
    
    printNode(root);
    PreOrder(root->left);
    PreOrder(root->right);
}


void InOrder(TreeNode* root)
{
    if(root==NULL)
        return;
    
    InOrder(root->left);
    printNode(root);
    InOrder(root->right);
        
}

void PostOrder(TreeNode* root)
{
    if(root==NULL)
        return;
    
    PostOrder(root->left);
    PostOrder(root->right);
    printNode(root);
}
int main()
{
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
//                 <- 3        6                  <- 2 ->
//                5                              9       8
           
                                
                                
//PreOrder:
//  10,    15,3,5,6,          30,2,9,8  
cout<<"\n\nPrinting Pre-Order traversal\n";    
PreOrder(newn);                          
    
    
    
//                               <- 10 -> 
//                     <- 15 ->             30 ->
//                 <- 3        6                  <- 2 ->
//                5                              9       8
           
    
    
//InOrder:
//5, 3, 15, 6, 10, 30, 9,2,8    
cout<<"\n\nPrinting In-Order traversal\n";
InOrder(newn);    
    
    
    
//                               <- 10 -> 
//                     <- 15 ->             30 ->
//                 <- 3        6                  <- 2 ->
//                5                              9       8
           
    
cout<<"\n\nPrinting Post-Order traversal\n";
PostOrder(newn);    

return 0;
}