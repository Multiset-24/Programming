#include <bits/stdc++.h>
using namespace std;

vector<int> convertor(vector<int> &v)
{
    int n = v.size();
    vector<int> result(n, 0);

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] < v[i] || (v[j] == v[i] && j < i)) {
                count++;
            }
        }
        result[i] = count;
    }
    return result;
}

void set_vector(vector<int> &v)
{
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
    cout << endl;
}

void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++) {
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
    vector<int> result = convertor(p);
    display(result);
    return 0;
}
