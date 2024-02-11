// 1
#include <bits/stdc++.h>
using namespace std;
void countTriplets(vector<int>& v)
{

    int x;
    cout << "Enter the target element\n";
    cin >> x;

    int countm = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size()-1; j++)
        {
            for (int k = j + 1; k < v.size()-2; k++)
            {
                if (v[i] + v[j] + v[k] == x)
                    countm++;
            }
        }
    }

    cout << countm;
    cout << endl;
    // return;
}

int main()
{
    vector<int> v;

    //  for(int i=0;i<v.size();i++){
    //     int q;
    //     cin>>v.push_back(q);
    //  };

    v.push_back(-1);
    v.push_back(-2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(-5);
    v.push_back(-9);
    v.push_back(8);
    v.push_back(7);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    countTriplets(v);

    return 0;
}