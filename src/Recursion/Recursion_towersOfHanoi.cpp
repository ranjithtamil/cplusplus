#include <iostream>
using namespace std;
void TowersofHanoi(int ndisks, char from, char to, char aux)
{
    if(ndisks==1)
    {
        cout<<"\nMove disk from "<<from<<" to "<<to<<"\n";
        return;
    }
    
    TowersofHanoi(ndisks-1,from,aux,to);
    cout<<"\nMoving remaining disk "<<ndisks<<" from "<<from<<" to "<<to;
    
    TowersofHanoi(ndisks-1,aux,to,from);
}

int main()
{
    int ndisks=3;
    char from ='A';
    char to ='C';
    char aux='B';
    TowersofHanoi(ndisks,from,to,aux);
    return 0;
}
