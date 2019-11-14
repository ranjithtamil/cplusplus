//g++  5.4.0
//https://www.geeksforgeeks.org/find-maximum-or-minimum-in-binary-tree/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node *left;
    Node *right;
};

Node* newNode(int data) {
    Node* temp= new Node();
    temp->val = data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int findMax(Node* root) {
    if(root == NULL) {
        return INT_MIN;
    }
    
    
    if(root!=NULL) {
        int max = root->val;
        int leftval = findMax(root->left);
      
        if(leftval > max) {
            max = leftval;
        }  
       
        int rightval = findMax(root->right);
        
        if(rightval > max) {
            max = rightval;
        }
        return max;
    }
}
int main()
{
    Node* root;
    root=newNode(1);
    root->left=newNode(2);
    root->left->left=newNode(4);
    root->left->left->right=newNode(7);
    
    root->right=newNode(3);
    root->right->left=newNode(5);
    root->right->right=newNode(6);
    root->right->left->left=newNode(8);
    root->right->left->right=newNode(9);
    
    int maximumval = findMax(root);
    cout<<"\nMax is "<<maximumval;
    return 0;
    //std::cout << "Hello, world!\n";
}
