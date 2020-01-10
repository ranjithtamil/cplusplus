#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class TreeNode {
  public:
    int val;
    TreeNode* left;
    TreeNode* right;
 
    TreeNode(int x) {
      val=x;
      left=NULL;
      right=NULL;
    }
};

void printResult(vector<int>& result) {
  for(int i=0;i<result.size();i++) {
    cout<<" "<<result.at(i);
  }
}

void postOrderPrintResult(vector<int>& result) {
  for(int i=result.size()-1;i>=0;i--) {
    cout<<" "<<result.at(i);
  }
}

void preOrder(TreeNode* root, vector<int>& result) {
  //Output should be 1 2 3 8 5 7 4 6
  /*  Algorithm
        1. Push Root to Stack
        2. while(stack is not empty) {
              pop stack top;
              PROCESS element;
              push element->right to stack;
              push element->left to stack;
            }
  */

  stack<TreeNode*> myStack;

  if(root==NULL) { return; }

  myStack.push(root);

  while(!myStack.empty()) {
    TreeNode* element= myStack.top();
    myStack.pop();

    if(element!=NULL) {
      result.push_back(element->val);
    }

    if(element->right) {
      myStack.push(element->right);
    }
    if(element->left) {
      myStack.push(element->left);
    }
  }


}

void inOrder(TreeNode* root, vector<int>& result) {
  //Output should be 8 3 2 7 5 1 4 6
  /*  Algorithm
        1. Store root as curr
        2. while(curr!=NULL || myStackNotEmpty) { 
                //curr!=NULL for first time entering. First time, stack is empty but current is NON-NULL

              while(curr!=NULL) {
                keep pushing current to stack.
                Update current=current->left;
              }

              Pop Stack top
              PROCESS element.

              Update Current=current->right;
            }
  */
  stack<TreeNode*> myStack;
  TreeNode* curr=root;
  while(curr!=NULL || !myStack.empty()) {

    while(curr!=NULL) {
      myStack.push(curr);
      curr=curr->left;
    }

    curr=myStack.top();
    myStack.pop();
    result.push_back(curr->val);
    curr=curr->right;
  }
}

void postOrder(TreeNode* root, vector<int>& result) {
  //Output should be 8 3 7 5 2 6 4 1
  //If we get 1 4 6 2 5 7 3 8, then the output is a reverse of it.
  //1 4 6 2 5 7 3 8 is like preOrder, but it is of order [ O R L ] instead of [ O L R ]. 

  stack<TreeNode*> myStack;
  if(root==NULL) {return;}

  myStack.push(root);

  while(!myStack.empty() ) {
    
    TreeNode* element=myStack.top();
    myStack.pop();

    result.push_back(element->val);

    if(element->left) {
      myStack.push(element->left);
    }

    if(element->right) {
      myStack.push(element->right);
    }

  }

}

int main() {
  TreeNode* root=new TreeNode(1);
  root->left=new TreeNode(2);
  root->right=new TreeNode(4);

  root->left->left=new TreeNode(3);
  root->left->right=new TreeNode(5);
  root->left->right->left=new TreeNode(7);

  root->left->left->left=new TreeNode(8);

  root->right->right=new TreeNode(6);

  vector<int> preOrderResult;
  vector<int> inOrderResult;
  vector<int> postOrderResult;

  cout<<"\nPreOrder Results\n";
  preOrder(root,preOrderResult);
  printResult(preOrderResult);

  cout<<"\nInOrder Results\n";
  inOrder(root,inOrderResult);
  printResult(inOrderResult);

  cout<<"\nPostOrder Results\n";
  postOrder(root,postOrderResult);
  postOrderPrintResult(postOrderResult); //This printing will be reverse of Result vector!!!

  return 0;
}
