#include <bits/stdc++.h>
using namespace std;
//gpt method
vector<int> convertor01(vector<int> &v)
{
    int n = v.size();
    vector<int> result(n, 0);

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j] < v[i] || (v[j] == v[i] && j < i))
            {
                count++;
            }
        }
        result[i] = count;
    }
    return result;
}
//for all but takes extra space
vector<int> convertor02(vector<int> &v)
{
    int n = v.size();
    vector<int> c(n, 0);
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        int min_idx = 0;
        int min_ele = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (c[j] == 1)
            {
                continue;
            }
            else
            {
                if (v[j] < min_ele)
                {
                    min_ele = v[j];
                    min_idx = j;
                }
            }
        }
        v[min_idx] = x;
        c[min_idx] = 1;
        x++;
    }
    return v;
}
//this method is for +ve numbers only
vector<int> convertor03(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int min_idx = 0;
        int min_ele = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (v[j] <= 0)
            {
                continue;
            }
            else
            {
                if (v[j] < min_ele)
                {
                    min_ele = v[j];
                    min_idx = j;
                }
            }
        }
        v[min_idx] = -i;
    }
    return v;
}

void set_vector(vector<int> &v)
{
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }
    cout << endl;
}

void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> p(n);
    set_vector(p);
    vector<int> result = convertor01(p);
    display(result);
    // convertor02(p);
    // display(p);
    convertor03(p);
    display(p);
    return 0;
}
