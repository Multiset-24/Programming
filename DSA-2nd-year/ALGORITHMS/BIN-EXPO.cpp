#include <bits/stdc++.h>
using namespace std;

//iterative approach
double myPow(double x, int n) {
        double ans=1.00;
        while(n--){
            ans=ans*x;
        }
        return ans;
    }
int main() {
    cout<<myPow(2.00,10);
    return 0;
}