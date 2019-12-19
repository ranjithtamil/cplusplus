//g++  5.4.0
/*
https://www.geeksforgeeks.org/array-rotation/
Juggling Algorithm
https://stackoverflow.com/questions/23321216/rotating-an-array-using-juggling-algorithm
*/
#include <iostream>
using namespace std;
int gcd( int a, int b ) {
    if( b==0 ) {
        return a;
    }
    else {
        return gcd( b, a%b );
    }
}
void rotateArray( int arr[], int n, int d ) {
    int nsets = gcd( n,d );
    cout<<"nsets = "<<nsets;
    for( int i=0; i<nsets; i++ ) {
        int j=i;
        int temp = arr[i];
        while( 1 ) {
            int k= (j+d)%n;
            if(k==i) {
                //cout<<"\nk = "<<k;
                break;
            }
            arr[j]=arr[k];
            cout<<"\nSwapping "<<j<<" and "<<k<<" locations";
            j=k;
        }
        arr[j]=temp;
    }
}
void printArray( int arr[], int n ) {
    for( int i=0; i<n; i++ ) {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[] = { 0,1,2,3,4,5,6 };
    int n=( sizeof(arr)/sizeof(int) );
    int d=2;
    rotateArray( arr,n,d );
    printArray( arr,n );
    return 0;
}



/*
How does the GCD decide the number of cycles needed to rotate the array?

Because the inner loop increments in steps of d, and stops when it gets back to the starting point, i.e. a total span which is some multiple of n. That multiple is LCM(n, d). Thus the number of elements in that cycle is LCM(n, d) / d. The total number of such cycles is n / (LCM(n, d) / d), which is equal to GCD(n, d).

Why is it that once we finish a cycle, we start the new cycle from the next element i.e. can't the next element be already a part of a processed cycle?

No. The inner loop increments in steps of d, which is a multiple of GCD(n, d). Thus by the time we start the i-th cycle, for a hit we'd need (k*GCD + z) % n == i (for 0 <= z < i). This leads to (k*GCD) % n == (i - z). This clearly has no solutions.
*/
