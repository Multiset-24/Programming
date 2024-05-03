#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
// Function to compute x raised to the power of n using binary exponentiation
long long binaryExponentiation(long long x, long long n) {
    long long result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = result * x%mod;
        }
        x = x * x%mod; // Square x
        n = n / 2; // Divide n by 2
    }
    return result;
}
int main() {
    ll n;
    cin>>n;


    ll num=binaryExponentiation(2,n);

    cout<<num;
    return 0;
}