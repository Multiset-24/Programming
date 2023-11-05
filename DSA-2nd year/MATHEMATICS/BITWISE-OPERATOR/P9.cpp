#include <bits/stdc++.h>
using namespace std;
// this concept is useful of CP
//print the factorial of first 25 natural numbers and modulo the result by 10^9 + 7
vector<long long>factorial(int n){
    vector<long long>v(n+1,1);
    int m=1000000007;
    for (int i = 2; i <= n; i++)
    {
        v[i]= ((i%m)*(v[i-1]%m))%m;
    }
    return v;
}

int main() {
    vector<long long>num=factorial(25);
    for (int i = 0; i < num.size(); i++)
    {
        cout<<"modulo of "<<i<<"! with 10^9+7 is "<<num[i]<<endl;
    }
    
    return 0;
}
