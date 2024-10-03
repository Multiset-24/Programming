#include <bits/stdc++.h>
using namespace std;
// selection sort algo
//algo simple hai ek baar iterate karo sbse chhota vala dhudo aur swap kardo first element se that's it!
vector<int> sort_selec(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = 0;
        int min_ele = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (v[j] < min_ele)
            {
                min_ele = v[j];
                min_idx = j;
            }
        }
        swap(v[i], v[min_idx]);
    }
    return v;
}
void set_vector(vector<int> &v)
{
    cout << "Enter the elements of the array-";
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
    cout << "Enter the size of the array-";
    cin >> n;
    vector<int> s(n);
    set_vector(s);
    sort_selec(s);
    display(s);
    return 0;
}