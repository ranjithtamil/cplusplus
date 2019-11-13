//g++  5.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    Node( int data ) {
        this->val = data;
        left = NULL;
        right = NULL;
    }
};

void inOrder( struct Node* root ) {
    if( root!=NULL ) {
        inOrder(root->left);
        cout <<" " <<root->val;
        inOrder(root->right);
    }
}
int BFS( struct Node* root, int key ) {
    if( root->val == key ) {
        return 1;
    }
    
    queue<struct Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        struct Node* temp = q.front();
        q.pop();
        
        if(temp->left!=NULL) {
            if(temp->left->val == key ) {
                return 1;
            }
            else {
                q.push(temp->left);
            }
        }
        
        if(temp->right!=NULL) {
            if(temp->right->val == key ) {
                return 1;
            }
            else {
                q.push(temp->right);
            }
        }
    }
    
    
    return -1;
}
int main()
{
    struct Node* root = new Node(1);                                                         
    root->left = new Node(3);
    root->right = new Node(24);
    
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    
    root->right->left = new Node(55);
    
    inOrder(root);
    
    int key=25;
    
    int found= -1;
    found=BFS(root, key);
    if(found == 1) {
        cout<<"\nFound";
    }
    if(found==-1) {
        cout<<"\nNOT FOUND";
    }
    return 0;
    //std::cout << "Hello, world!\n";
}
