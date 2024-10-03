#include <bits/stdc++.h>
using namespace std;
// sort a string in decreasing order of values associated afet removal of values smaller than x using all type of basic sorting

// bubble sort way
string pro_blem1(string &s)
{
    string _s;
    int n = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'X')
        {
            _s.push_back(s[i]);
        }
    }
    if (_s == "NULL")
        return 0;
    for (int i = 0; i < _s.size() - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < _s.size() - 1 - i; j++)
        {
            if (_s[j] > _s[j + 1])
            {
                swap(_s[j], _s[j + 1]);
                flag = false;
            }
        }
        if (flag == true)
        {
            break;
        }
    }
    return _s;
}
// selection sort way
string pro_blem2(string &s)
{
    int n = s.size();
    string _s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'X')
        {
            _s.push_back(s[i]);
        }
    }
    for (int i = 0; i < _s.size() - 1; i++)
    {
        int min_idx = 0;
        int min_ele = INT_MAX;
        for (int j = i; j < _s.size(); j++)
        {
            if (_s[j] < min_ele)
            {
                min_idx = j;
                min_ele = _s[j];
            }
        }
        swap(_s[i], _s[min_idx]);
    }
    return _s;
}
// insertion sort way
string pro_blem3(string &s)
{
    int n=s.size();
    string _s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'X')
        {
            _s.push_back(s[i]);
        }
    }
    for (int i = 1; i <_s.size() ; i++)
    {
        int j=i;
        while(j>=1&&_s[j]<_s[j-1]){
            swap(_s[j],_s[j-1]);
            j--;
        }
    }
    return _s;
}
int main()
{
    string s ;
    cout<<"Enter the array-";
    cin>>s;
    string g = pro_blem3(s);
    cout << g;
    return 0;
}