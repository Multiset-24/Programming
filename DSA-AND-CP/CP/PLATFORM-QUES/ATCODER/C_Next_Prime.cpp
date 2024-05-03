#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int,int> pi;
#define u_mp unordered_map 
#define u_st unordered_set 
template<typename T>

// Function templates for reading input
void read(T& t) {
    cin >> t;
}
template<typename T, typename... Args>
void read(T& t, Args&... args) {
    cin >> t;
    read(args...);
}

// Debugging macro
#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //precomputation of prime numbers
    vector<int> primes;
    vector<bool> is_prime(1000001, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= 1000000; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= 1000000; j += i) {
                is_prime[j] = false;//we marked all the multiples of i as false
            }
        }
    }

    int n;
    read(n);

    for (int i = 0; i < primes.size(); i++) {
        if (primes[i] >= n) {
            cout << primes[i] << endl;
            break;
        }
    }
    return 0;
}