// Unset the rightmost set bit of an integer. 
// n - 1 will have rightmost 1 bit unset, but also all lower 0 digits flipped(i.e., set). So doing AND of n, n-1 will give answer.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

int main() {
    int n = 0b110;
    int ans = (n & (n-1));
    cout<<ans<<"\nBinary Representation:\n";
    unsigned char byte0 = (ans & 0xFF);
    unsigned char byte1 = (ans >> 8) & (0xFF);
    unsigned char byte2 = (ans >> 16) & (0xFF);
    unsigned char byte3 = (ans >> 24) & (0xFF);
   
    printf("%c%c%c%c%c%c%c%c",BYTE_TO_BINARY(byte3));
    printf("%c%c%c%c%c%c%c%c",BYTE_TO_BINARY(byte2));
    printf("%c%c%c%c%c%c%c%c",BYTE_TO_BINARY(byte1));
    printf("%c%c%c%c%c%c%c%c",BYTE_TO_BINARY(byte0));
    return 0;   
}
