#include <bits/stdc++.h>
using namespace std;
//method 1 by taking xor of number with the help of a number which has all the number as 1's in it's binary form 
//<------------------>
int convert_to_all_1(int n){
    for (int i = 0; i < 6; i++)
    {
        n=n|(n>>(1<<i));
    }
    return n;
}

int flip_the_number(int n){
     int m=convert_to_all_1(n);
     return n^m;
}
//<------------------>

//method 2
int main() {
    int n;
    cin>>n;
    cout<<flip_the_number(n);
    return 0;
}