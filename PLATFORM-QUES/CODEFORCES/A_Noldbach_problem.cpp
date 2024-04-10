#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int, int> pi;
#define u_mp unordered_map
#define u_st unordered_set
template <typename T>

// Function templates for reading input
void read(T &t)
{
    cin >> t;
}
template <typename T, typename... Args>
void read(T &t, Args &...args)
{
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
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    read(n, k);

    vector<bool> is_prime(n + 1, true);

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++)//Sieve of Eratosthenes
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }

    int count = 0;
    u_st<int> prime_set;

    for (int i = 0; i < primes.size() - 1; i++)
    {
        prime_set.insert(primes[i] + primes[i + 1]);
    }

    for(auto x:primes){
        if(prime_set.find(x-1)!=prime_set.end()){
            count++;
        }
    }

    if (count >= k)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}