//Make Union Find Algorithm
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int rank;
        Node* parent;
        long data;
};
class MUF {
public:
unordered_map<long,Node*>findNode;
void makeSet(long data);
void Union(long data1, long data2);
Node* findSet(Node* node1);
long FINDSET(long val);
};
long MUF::FINDSET(long data) {
    Node* node1 = findNode[data];
    Node* dataSet = findSet(node1);
    return dataSet->data;
}
void MUF::makeSet(long data) {
    Node* node1 = new Node;
    node1->rank=0;
    node1->parent=node1;
    node1->data=data;
    findNode[data]=node1;
}
void MUF::Union(long data1, long data2) {
    Node* node1 = findNode[data1];
    Node* node2 = findNode[data2];
    
    Node* parent1 = findSet(node1);
    Node* parent2 = findSet(node2);
    
    if(parent1==parent2) {
        return;
    }
    
    int rank1 = parent1->rank;
    int rank2 = parent2->rank;
    
    
    if(rank1 >= rank2) {
        if(rank1==rank2) {
            parent2->parent=parent1;
            parent1->rank=parent1->rank + 1;
        }
        else {
            parent2->parent=parent1;
        }
    }
    else {
        parent2->parent=parent1;
    }
}

Node* MUF::findSet(Node* node1) {     //path compression
    Node* parent = node1->parent;
    if(parent == node1) {
        return parent;
    }
    node1->parent = findSet(node1->parent);
    return node1->parent;
}
int main()
{
    MUF ds;
    ds.makeSet(1);
    ds.makeSet(2);
    ds.makeSet(3);
    ds.makeSet(4);
    ds.makeSet(5);
    ds.makeSet(6);
    ds.makeSet(7);
    
    ds.Union(1,2);
    /*
    cout<<"\n findSet(1) = "<<ds.FINDSET(1);
    cout<<"\n findSet(2) = "<<ds.FINDSET(2);
    */
    ds.Union(2,3);
    /*
    cout<<"\n findSet(1) = "<<ds.FINDSET(1);
    cout<<"\n findSet(2) = "<<ds.FINDSET(2);
    cout<<"\n findSet(3) = "<<ds.FINDSET(3);
    */
    ds.Union(4,5);
    /*
    cout<<"\n findSet(1) = "<<ds.FINDSET(1);
    cout<<"\n findSet(2) = "<<ds.FINDSET(2);
    cout<<"\n findSet(3) = "<<ds.FINDSET(3);
    cout<<"\n findSet(4) = "<<ds.FINDSET(4);
    cout<<"\n findSet(5) = "<<ds.FINDSET(5);
    */
    ds.Union(6,7);
    /*
    cout<<"\n findSet(1) = "<<ds.FINDSET(1);
    cout<<"\n findSet(2) = "<<ds.FINDSET(2);
    cout<<"\n findSet(3) = "<<ds.FINDSET(3);
    cout<<"\n findSet(4) = "<<ds.FINDSET(4);
    cout<<"\n findSet(5) = "<<ds.FINDSET(5);
    cout<<"\n findSet(6) = "<<ds.FINDSET(6);
    cout<<"\n findSet(7) = "<<ds.FINDSET(7);
    */
    ds.Union(5,6);
    /*
    cout<<"\n findSet(1) = "<<ds.FINDSET(1);
    cout<<"\n findSet(2) = "<<ds.FINDSET(2);
    cout<<"\n findSet(3) = "<<ds.FINDSET(3);
    cout<<"\n findSet(4) = "<<ds.FINDSET(4);
    cout<<"\n findSet(5) = "<<ds.FINDSET(5);
    cout<<"\n findSet(6) = "<<ds.FINDSET(6);
    cout<<"\n findSet(7) = "<<ds.FINDSET(7);
    */
    ds.Union(3,7);
    /*
    cout<<"\n findSet(1) = "<<ds.FINDSET(1);
    cout<<"\n findSet(2) = "<<ds.FINDSET(2);
    cout<<"\n findSet(3) = "<<ds.FINDSET(3);
    cout<<"\n findSet(4) = "<<ds.FINDSET(4);
    cout<<"\n findSet(5) = "<<ds.FINDSET(5);
    cout<<"\n findSet(6) = "<<ds.FINDSET(6);
    cout<<"\n findSet(7) = "<<ds.FINDSET(7);
    */
    
    
    return 0;
}
