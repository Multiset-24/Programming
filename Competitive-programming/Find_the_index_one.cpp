#include <bits/stdc++.h>
using namespace std;
// given an infinite array which consists of binary form of numbers from 1 to INF concatenated.
// 1 2 3 4 5 6 7 8 9...
// 1+10+11+100+101+110+111+1000+...
#define mod 1000000007
#define int long long
// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v)          \
    {                            \
        cout << #v << " = [";    \
        for (auto &elem : v)     \
            cout << elem << " "; \
        cout << "]" << endl;     \
    }
#define print_map(m)                                                  \
    {                                                                 \
        cout << #m << " = {";                                         \
        for (auto &pair : m)                                          \
            cout << "{" << pair.first << ": " << pair.second << "} "; \
        cout << "}" << endl;                                          \
    }
#define print_2dvector(v)             \
    {                                 \
        cout << #v << " = [" << endl; \
        for (auto &row : v)           \
        {                             \
            cout << "  [";            \
            for (auto &elem : row)    \
                cout << elem << " ";  \
            cout << "]" << endl;      \
        }                             \
        cout << "]" << endl;          \
    }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif
#define endl '\n'

string getBitStr(int number)
{
    string bitStr = "";
    while(number){
        if(number&1)bitStr.push_back('1');
        else bitStr.push_back('0');
        number>>=1;
    }
    reverse(bitStr.begin(),bitStr.end());
    return bitStr;
}

int pos_of_one_in_num(int m, int x)
{
    string s = getBitStr(x);

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            m--;
        }

        if (m == 0)
        {
            return i + 1;
        }
    }
    return 0;
}

int get_totol_bits(int x)
{
    int cnt = 1;

    int length = 1;
    int current_num = 1;

    while (current_num <= x)
    {
        int next_num = 2 * current_num;
        int n = next_num - 1;

        if (next_num <= x)
        {
            cnt += (length) * (n - current_num + 1);
        }
        else
        {
            cnt += (length) * (x - current_num + 1);
        }

        length++;
        current_num = next_num;
    }
    return cnt;
}

int find_no_ones(int n)
{
    int ones = 0;

    for (int i = 0; i < 62; i++)
    {   
        int periodicity = (1LL << (i + 1));
        int one_repeat = (1LL << i);
        int no_of_cycles = (n + 1) / periodicity;
        ones += (one_repeat * no_of_cycles);
        int extra_nums = (n + 1) % periodicity;
        int extra_ones = max(0LL, extra_nums - one_repeat);
        ones += extra_ones;
    }

    return ones;
}

int find_the_num(int k)
{
    int hi = k, lo = 0;
    int ans = -1;
    // cout<<"hello"<<endl;
    while (lo<=hi)
    {   
        // cout<<"hi "<<hi<<" lo "<<lo<<endl;
        int mid = lo + (hi - lo) / 2;

        if (find_no_ones(mid) >= k)
        {
            hi = mid - 1;
            ans = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ans;
}

void jarvis()
{
    /*
        Q. find the index of the kth one present in the INF array .
        solution->
                idea->since we need to find the kth val somehow it includes binary search like we use in 2d BS.

                now the question is reduced to -> {(# of one in [1...X])>=k}

                check function for BS->[
                        : for each pos we in bits of number it follows the cyclic property having a periodicity of 2^(i+1) O included where i is bit index in binary form

                        :2^i is the number of ones in one cycle then we can iterate over all bits this is the TECHNIQUE rather than iterating over numbers iterate over bits

                        :Now find the left out nums in the remaining numbers after cycle.

                        :if total ones in [1...X]>=k then that mid can be the potential answer .
                ]

                now find the number of ones in range [1...X-1] thus we will get the number of ones more we need to find the X


                After getting the to the number where our kth one is present , we need to find the index of 1 in that number

                now find the total number of bits from [1..X] say l thus the final answer will l+position in number
    */

    int k;
    cin >> k;

    // cout<<get_totol_bits(k)<<" ";
    // cout<<find_no_ones(6)<<" 1's"<<endl;
    // cout<<num<<" num of kth one "<<endl;
    int num = find_the_num(k);
    // cout<<"num "<<num<<" ";
    int no_of_one_in_num=k-find_no_ones(num-1);
    // cout<<no_of_one_in_num<<"n ";
    int pos_of_kth_one_in_num=pos_of_one_in_num(no_of_one_in_num,num);
    // cout<<pos_of_kth_one_in_num<<"h ";
    int total_bits=get_totol_bits(num-1);
    // cout<<total_bits<<" bits ";
    int kth_index=total_bits+(pos_of_kth_one_in_num);

    cout<<kth_index<<endl;
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