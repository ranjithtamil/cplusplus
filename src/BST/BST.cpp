#include<iostream>
using namespace std;
typedef struct BSTNode BSTNode;
struct BSTNode{
  int data;
  BSTNode* left;
  BSTNode* right;
};


//All values to left are smaller than rootnode.
//All values to right are greater than rootnode.

//50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80
//https://www.youtube.com/watch?v=COZK7NATh4k
BSTNode* Insert(BSTNode* root, int data);
void PreOrder(BSTNode* root);
void PostOrder(BSTNode* root);
void InOrder(BSTNode* root);

BSTNode* GetNewNode(int data)
{
  BSTNode* NewNode=new BSTNode();
  //(*NewNode).data=data;
  NewNode->data=data;
  NewNode->left=NULL;
  NewNode->right=NULL;
  return NewNode;
}
int main()
{
BSTNode* rootPtr;
rootPtr=NULL;
rootPtr=Insert(rootPtr,15);
rootPtr=Insert(rootPtr,20);
rootPtr=Insert(rootPtr,10);
rootPtr=Insert(rootPtr,25);
rootPtr=Insert(rootPtr,30);
rootPtr=Insert(rootPtr,35);
rootPtr=Insert(rootPtr,5);

PreOrder(rootPtr);
return 0;
}
BSTNode* Insert(BSTNode* root,int data)
{
  if(root==NULL)
  {
  root=GetNewNode(data);
  }
  else if(data<=(root->data))
  {
    root->left=Insert(root->left,data);
  }
  else
  {
  root->right=Insert(root->right,data);
  }

  return root;
}

void PreOrder(BSTNode* root)
{
  if(root)
  {
  cout<<(root->data)<<endl;
  PreOrder(root->left);
  PreOrder(root->right);
  }
}

void PostOrder(BSTNode* root)
{
  if(root)
  {
  PostOrder(root->left);
  PostOrder(root->right);
  cout<<(root->data)<<endl;
  }
}

void InOrder(BSTNode* root)
{
  if(root)
  {
  InOrder(root->left);
  cout<<(root->data)<<endl;
  InOrder(root->right);
  }
}
