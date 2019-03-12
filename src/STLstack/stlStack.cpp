#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

template <typename T>
void StackDebug(stack<T> s)
{
  vector<T> debugVector = vector<T>(); //vector<int> debugVector=vector<int>();
  while(!s.empty())
  {
    T t = s.top(); //if T is int, then int t=s.top();
    debugVector.push_back(t);
    s.pop();
  }

  //In this way, vector is created by popping stack from top and pushing at
  //back of vector.
  //So If stack was 9,11,12,7,4<-top
  //Then its pushed to vector as 4,7,12,11,9
  //We need to traverse from last then...(in the same order that stack was constructed)

  reverse(debugVector.begin(),debugVector.end());
  typename vector<T>::iterator it;
  for(it=debugVector.begin();it!=debugVector.end();++it)
  {
    cout<<*it<<" ";
  }
  cout<<"\n";
}
int main()
{

/***************************************************************/
  //Create Stack
  stack<int> mystack;
  //Insert into stack
  mystack.push(0);
  mystack.push(1);
  mystack.push(2);

  cout<<"\n Size_of_stack = "<<mystack.size()<<endl;
  //Print stack elements
  while(!mystack.empty())
  {
    cout<<" "<<mystack.top();
    mystack.pop();
  }
  cout<<"\n";

/***************************************************************/

//Incase you want to traverse a stack for debugging purposes
//https://stackoverflow.com/questions/23194548/how-to-traverse-stack-in-c

stack<int> numbers;
cout<<"\nStack Debug 9 11 12 7 4\n";
numbers.push(9);
numbers.push(11);
numbers.push(12);
numbers.push(7);
numbers.push(4);
StackDebug(numbers);

return 0;



}
