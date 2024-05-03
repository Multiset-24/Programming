#include <bits/stdc++.h>
using namespace std;
//the set bits for any integer n

//method 1
void count_set_bits(int num){
    cout<<__builtin_popcount(num);
}

//method 2-------> brain karnighan's algorithm
int count_set_bits2(int n){
int count=0;
while(n>0){
    n=n&(n-1);
    count++;
}
return count;
}
int main() {
    count_set_bits(64);
    cout<<endl<<count_set_bits2(66000);
    return 0;
}