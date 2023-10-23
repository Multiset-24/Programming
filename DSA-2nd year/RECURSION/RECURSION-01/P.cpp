#include <iostream>
using namespace std;
//Power function using recursion
long long pow(long long a,long long b){
    if(a==1) return 1;
    if(b==0) return 1;
    int res;
    res=a*pow(a,b-1);
    return res;
}
int main() {
 cout<<pow(2,30);
    return 0;
}