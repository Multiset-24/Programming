// C stands for concept thus c1 is concept 1 of lecture
#include <bits/stdc++.h>
using namespace std;

// 1d array ka first ques hai
void merge(vector<int> &a, vector<int> &b, vector<int> &r)
{
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
            r[k++] = a[i++];
        else
            r[k++] = b[j++];
    }
    if (i == a.size())
    {
        while (j < b.size())
            r[k++] = b[j++];
    }
    if (j == b.size())
    {
        while (i < a.size())
            r[k++] = a[i++];
    }
}
void mergesort(vector<int> &v)
{
    int n = v.size();
    if(n==1) return;
    int n1 = n / 2, n2 = n - (n / 2);
    vector<int> A(n1), B(n2);
    for (int i = 0; i < n1; i++)
    {
        A[i] = v[i];
    }
    for (int i = 0; i < n2; i++)
    {
        B[i] = v[n1 + i];
    }
    mergesort(A);
    mergesort(B);
    merge(A, B, v);
    A.clear();
    B.clear();
}
int main()
{
    vector<int> v(10);
    for (int i = 0; i < 10; i++)
    {
        cin>>v[i];
    }
    
    mergesort(v);
    for (int i = 0; i < 10; i++)
    {
        cout << v[i]<<" ";
    }

    return 0;
}
