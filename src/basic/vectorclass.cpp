
#include <iostream>
using namespace std;
class Vector{
  private:
    double* elem;
    int size;
  public:
    double& operator[](int i)
    {
        return elem[i];
    }
    Vector(int sze)
    {
        size=sze;
        elem=new double[sze];
    }
};
int main()
{
    Vector V(7);
    V[0]=1;
    V[1]=2;
    V[2]=3;
    V[3]=4;
    V[4]=5;
    V[5]=6;
    V[6]=7;
    
    for(int i=0;i<7;i++)
    {
        cout<<V[i]<<"\n";
    }
	return 0;
}
