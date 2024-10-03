#include <bits/stdc++.h>
using namespace std;
// algo for insertion sort and it's code
//ek element aage se shuru karo aur while loop mai tb tk chalao jb tk pichhe vala element aage vale se bada ho phir exit lelo
vector<int> sort_insert(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j >= 1 && v[j] < v[j - 1])
        {
            swap(v[j], v[j - 1]);
            j--;
        }
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
    vector<int> i(n);
    set_vector(i);
    display(i);
    sort_insert(i);
    display(i);
    return 0;
}