#include <bits/stdc++.h>
using namespace std;

#define int long long

int monster_game(int h)
{ 
    return (h == 1) ? 1 : 2 * (monster_game(h / 2)) + 1;
}

int32_t main()
{
    int h;
    cin >> h;

    cout << monster_game(h);

    return 0;
}
