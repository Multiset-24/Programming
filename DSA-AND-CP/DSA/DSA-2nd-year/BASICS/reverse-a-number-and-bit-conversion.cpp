// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//  long long x;
//  cin>>x;
//  int i=0,ans=0;
// int bit;
//  while(x!=0){
//     bit=x & 1;
//     ans=(bit * pow(10 , i))+ans;
//     x>>=1;
//     i++;
//  }
//  cout<<ans;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin >> x;
    
    int i = 0, ans = 0;
    int bit;
    
    while (x != 0) {
        bit = x & 1;
        ans = (bit * pow(10, i)) + ans;
        x >>= 1;\
        i++;
    }
    
    cout << ans;
    return 0;
}
