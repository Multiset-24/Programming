#include <bits/stdc++.h>
using namespace std;
//find the maximum power of 2 taht is smaller than n
// we can also use brute force approach like converting the number into binary then count the position of last 1 one and using that find the minimum power of 2 close r to number BUT HERE WE WILL USE "BRIAN KARNIGHAN'S ALGORITHM" TO FIND THIS 

// GOOD APPROACH

int minimum_power_of_2(int n){
    int temp;
    while (n>0)
    {
        temp=n;
        n=n&(n-1);
    }
    return temp;
}
int maximum_power_of_2(int n){
    int temp;
    while (n>0)
    {
        temp=n;
        n=n&(n-1);
    }
    return temp<<1;
}

//another approach-- using right shift and or bitwise operator

int max_pow_of_2(int n){
    for (int i = 0; i <5; i++)
    {
    n=n|(n>>(1<<i));
    }
return (n+1);
}
int main() {
    cout<<minimum_power_of_2(65);
    cout<<endl<<maximum_power_of_2(65);
    cout<<endl<<max_pow_of_2(65);
    return 0;
}