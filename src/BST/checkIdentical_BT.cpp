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
int sameTree(TreeNode* p,TreeNode* q)
{
    if(p==NULL && q==NULL)
    {
        return true;
    }
    else
    {
        if(p!=NULL && q!=NULL)
        {
            if(p->val==q->val && sameTree(p->left,q->left) && sameTree(p->right,q->right))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
    }
    return false;
}
int main()
{
     TreeNode* a=new TreeNode(10);
    //printNode(newn);
    a->left=new TreeNode(15);
    a->left->left=new TreeNode(3);
    a->left->left->left=new TreeNode(5);
    a->left->right=new TreeNode(6);
    a->right=new TreeNode(30);
    a->right->right=new TreeNode(2);
    a->right->right->left=new TreeNode(9);
    a->right->right->right=new TreeNode(8);
    
    
//                               <- 10 -> 
//                     <- 15 ->             30 ->
//                 <- 3        6                  <- 2 ->
//                5                              9       8
           
    
     TreeNode* b=new TreeNode(10);
    //printNode(newn);
    b->left=new TreeNode(15);
    b->left->left=new TreeNode(3);
    b->left->left->left=new TreeNode(5);
    b->left->right=new TreeNode(6);
    b->right=new TreeNode(30);
    b->right->right=new TreeNode(2);
    b->right->right->left=new TreeNode(9);
    b->right->right->right=new TreeNode(8);
    
    
//                               <- 10 -> 
//                     <- 15 ->             30 ->
//                 <- 3        6                  <- 2 ->
//                5                              9       8
           
    
    int isSameTree=sameTree(a,b);
    cout<<"\n isSameTree = "<<isSameTree;
    return 0;
    //std::cout << "Hello, world!\n";
}
