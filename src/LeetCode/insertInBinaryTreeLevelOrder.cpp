//g++  5.4.0
https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/



#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        this->data=val;
        left=NULL;
        right=NULL;
    }
};

void inOrder( struct Node* root ) {
    if(root != NULL) {
        inOrder( root->left );
        cout<<" "<<root->data;
        inOrder( root->right );
    }
}
int insert( struct Node* root, int val ) {
    queue<struct Node*> q;
    q.push(root);
    int result = 0;
    
    while(!q.empty()) {
        struct Node* temp = q.front();
        q.pop();
        
        if(temp->left == NULL) {
            temp->left = new Node(val);
            result=1;
            break;
        }
        else {
            q.push(temp->left);
        }
        
        if(temp->right == NULL) {
            temp->right = new Node(val);
            result=1;
            break;
        }
        else {
            q.push(temp->right);
        }
    }
    
    return result;
}

int main()
{
  struct Node* root=new Node(10);
  root->left=new Node(11);
  root->left->left=new Node(7);
  root->right=new Node(9);
  root->right->left=new Node(15);
  root->right->right=new Node(8);
  
  cout<<"\n Inorder Representation of Tree before insertion\n ";
  inOrder(root);
  int key1 = 99;
    
  int res = insert( root, key1 );
    if(res != 1 ) {
        cout<<"\nERROR!";
    }
  int key2 = 199;
    
  res = insert( root, key2 );
     if(res != 1 ) {
        cout<<"\nERROR!";
    }
  int key3 = 299;
    
  res = insert( root, key3 );
    if(res != 1 ) {
        cout<<"\nERROR!";
    }
  cout<<"\n Inorder Representation of Tree after insertion\n ";  
  inOrder(root);
  return 0;  
    //std::cout << "Hello, world!\n";
}
