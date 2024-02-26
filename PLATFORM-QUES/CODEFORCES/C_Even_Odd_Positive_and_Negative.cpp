#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int, int> pp;

int main()
{
    int n;
    cin >> n;
    int even = 0, odd = 0;
    int pos = 0, neg = 0;
    while (n--)
    {
        int x;
        cin >> x;

        if (x % 2 == 0)
        {
            even++;
            if (x > 0)
            {
                pos++;
            }
            else if (x < 0)
            {
                neg++;
            }
        }
        else if (x % 2 != 0)
        {
            odd++;
            if(x>0){
                pos++;
            }else if(x<0){
                neg++;
            }
        }
    }
        cout << "Even: " << even <<endl<< " Odd: " << odd <<endl<< " Positive: " << pos <<endl<< " Negative: " << neg << endl;    
        return 0;
    }