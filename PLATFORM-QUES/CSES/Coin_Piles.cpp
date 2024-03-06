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

//--------------------End of Template---------------------

// This is a recusrsive solution but it is not working for large inputs and it is giving TLE

// bool solve_rec(int a,int b){
//     if(a==0 && b==0){
//         return true;
//     }//why this is working
//     if(a<=0 || b<=0){
//         return false;
//     }
//     return solve_rec(a-2,b-1) || solve_rec(a-1,b-2);
// }

// This is the iterative solution for the problem

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;
/*
        When both piles have 0 coins 

        a=2*x+y
                \
                solving x=2b-a/3 and y=2a-b/3 if both x and y are non negative then we can say that the operation is possible;
                /
        b=2*y+x;

*/



    while (Q--)
    {
        int a, b;
        read(a, b);

        if ((2 * b - a) % 3 == 0 && (2 * a - b) % 3 == 0 && (2 * b - a) >= 0 && (2 * a - b) >= 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}