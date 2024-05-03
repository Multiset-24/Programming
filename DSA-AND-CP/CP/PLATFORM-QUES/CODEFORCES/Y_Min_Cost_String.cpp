#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
typedef pair<int, int> pp;

#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int cost[26];
    for (int i = 0; i < 26; i++)
    {
        cin >> cost[i];
    }

    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            int j = i;
            while (j < n && s[j] == '?')
            {
                j++;
            }
            // this is for the test case in which some of first starting characters are '?'
            if (i == 0 && j < n)
            {
                while (i < j)
                {
                    s[i] = s[j];
                    i++;
                }
                continue;
            } // this is for the test case in which some of last ending characters are '?'
            else if (i > 0 && j == n)
            {
                while (i < j)
                {
                    s[j - 1] = s[i - 1];
                    j--;
                }
                break;
            } // this is for the test case in which all characters are '?'
            else if (i == 0 && j == n)
            {
                for (int k = 0; k < n; k++)
                {
                    s[k] = 'a';
                }
                break;
            } // this is for the test case in which some of the characters are '?' in the middle of the string
            int left = INT_MAX;
            if (i != 0)
                left = cost[s[i - 1] - 'a'];
            int right = INT_MIN;
            if (j != n)
                right = cost[s[j] - 'a'];
            int min_cost = min(left, right);
            int max_cost = max(left, right);
            for (int k = 0; k < 26; k++)
            {
                if (cost[k] >= min_cost && cost[k] <= max_cost)
                {
                    for (int l = i; l < j; l++)
                    {
                        s[l] = k + 'a';
                    }
                    break;
                }
            }
            i = j;
        }
    }
    int min_cost = 0;
    for(int i=0;i<s.size()-1;i++){
        min_cost +=abs(cost[s[i]-'a']-cost[s[i+1]-'a']);
    }

    cout<<min_cost<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }
    return 0;
}


//someone else solution


/*#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    string str;
    int cost[26];
    cin >> str;
    for (int i = 0; i < 26; i++)
    {
        cin >> cost[i];
    }
     int question_counter = 0;

    for (int i = 0; i < str.size(); i++)
    {
         question_counter = 0;
        if (str[i] == '?')
        {

            for (int j = i; j < str.size(); j++)
            {
                if (str[j] == '?')
                {
                    question_counter++;
                }
                else
                {
                    break;
                }
            }

            // str =  ???????
            if (question_counter == str.size())
            {
                cout << 0 << endl;
                for (int j = 0; j < str.size(); j++)
                {
                    cout << "a";
                }

                // end program
                return 0;
            }
            else
            {
                // str = ???abcd
                if (i == 0)
                {
                    int min = INT_MAX, index;

                    // find first min cost char
                    for (int z = 0; z < (str[question_counter] - 97) + 1; z++)
                    {
                        int current_cost = abs(cost[str[question_counter] - 97] - cost[z]);
                        if (min > current_cost)
                        {
                            min = current_cost;
                            index = z;
                        }
                    }

                    // replace the question marks with min char
                    char replacement_char = index + 97;
                    for (int j = 0; j < question_counter; j++)
                    {
                        str[j] = replacement_char;
                    }

                    i += question_counter;
                }

                // str = abcd???
                else if (i + question_counter == str.size())
                {
                    int min = INT_MAX, index;

                    // find first min cost char
                    for (int z = 0; z < (str[i - 1] - 97) + 1; z++)
                    {
                        int current_cost = abs(cost[str[i - 1] - 97] - cost[z]);
                        if (min > current_cost)
                        {
                            min = current_cost;
                            index = z;
                        }
                    }

                    // replace the question marks with min char
                    char replacement_char = index + 97;

                    for (int j = i; j < question_counter + i; j++)
                    {
                        str[j] = replacement_char;
                    }

                    break;
                }
                // str = adb??sks
                else
                {
                    int min = INT_MAX, index;
                    // loop to find min cost in whole alphabet
                    for (int x = 0; x < 26; x++)
                    {
                        int current_cost = abs(cost[str[i - 1] - 97] - cost[x]) + abs(cost[x] - cost[str[i + question_counter] - 97]);
                        if (min > current_cost)
                        {
                            min = current_cost;
                            index = x;
                        }
                    }

                    // replace the question marks with min char
                    char replacement_char = index + 97;

                    for (int j = i; j < i + question_counter; j++)
                    {
                        str[j] = replacement_char;
                    }

                    i += question_counter;
                }
            }
        }
    }

    long long final_cost = 0;
    for (int i = 0; i < str.size() - 1; i++)
    {
        final_cost += abs(cost[str[i] - 97] - cost[str[i + 1] - 97]);
    }

    cout << final_cost << endl;
    cout << str << endl;
}*/