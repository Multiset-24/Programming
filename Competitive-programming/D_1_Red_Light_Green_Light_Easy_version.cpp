#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v) { cout << #v << " = ["; for (auto &elem : v) cout << elem << " "; cout << "]" << endl; }
#define print_map(m) { cout << #m << " = {"; for (auto &pair : m) cout << "{" << pair.first << ": " << pair.second << "} "; cout << "}" << endl; }
#define print_2dvector(v) { cout << #v << " = [" << endl; for (auto &row : v) { cout << "  ["; for (auto &elem : row) cout << elem << " "; cout << "]" << endl; } cout << "]" << endl; }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif
#define endl '\n'

/*
    QUESTION->
    hamare pass strip of length 1e15 
    n traffic light ki do array hai ek P(positions ke liy) and ek D(delay ke liy)
    thus Two arrays p1 p1 ..... pn and d1 d2 ..... dn

    Har ek traffic light red light show karegi at times t=l*k+di jaha l ek integer hai and k hume dia hua hai such that k>di for all i from [1 n] thus jiska mtlb hai l will always be a whole number l belongs to [0,inf] agr t!=l*k+di then green light show hogi

    now ek player start karega 0 se chlna agr vo kisi traffic light pe pahuchgta hai then do agr red hai to drxn change karlega phir forward move karege else green hai to sirf forward move karega pehle vali drxn mai hi 

    Now for q queries hume btana hai ki agr person qi position pe hai to kya vo strip ko escape kar payga ya nhi within 10^100 seconds i.e infinity

    SOLUTION-> 
    thinking 

*/
void jarvis()
{
    
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}