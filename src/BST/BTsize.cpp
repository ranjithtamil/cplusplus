//g++  5.4.0

#include <iostream>
using namespace std;

struct TreeNode
{
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
int sizecalc(TreeNode* root)
{
    if(root==NULL)
        return 0;
    else
    {
        return (sizecalc(root->left) + sizecalc(root->right) + 1);
    }
}
int main()
{
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
           
    
    
    int size_of_tree=sizecalc(newn);
    cout<<"\nSize of tree = "<<size_of_tree;
    return 0;
    //std::cout << "Hello, world!\n";
}
