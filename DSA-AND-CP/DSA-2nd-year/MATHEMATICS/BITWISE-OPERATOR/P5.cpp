#include <bits/stdc++.h>
using namespace std;
// write a program to count number of attempts required to convert into another numer....

int count_to_convert(int n,int m){
    int q=(n^m);
    int count=0;
    while(q>0){
         q=q&(q-1);//brian kernigham's algorithm
         count++;
    }
    return count;
}
int main() {
    cout<<count_to_convert(23,32);
    return 0;
}