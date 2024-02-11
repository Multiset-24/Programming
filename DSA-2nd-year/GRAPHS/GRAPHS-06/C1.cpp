#include <bits/stdc++.h>
using namespace std;
// implimentation of DSU
// approach 1..

class disjoint_set_1
{
    vector<int> parent;
public:
    disjoint_set(int n){
        parent.resize(n);

    }
    void make_set(int x){
        parent[x]=x;
    
    }
    
    int _find(int x)//time complexity of this operation is O(1)
    {
        if (parent.size() == 0)
        {
            cout << "No groups exist";
            return 0;
        }
        return parent[x];
    }

    void _union(int a, int b)//time complexity of this operation is O(n) we need to reduce this by some modifications
    {
        a = _find(a);
        b = _find(b);

        if (a != b)
        {
            for (int i = 0; i < parent.size(); i++)
            {
                if (parent[i] == b)
                    parent[i] = a;
            }
        }
    }
};
#define mod 1000000007

int
main()
{
    
    disjoint_set_1 ds(6);

    for(int i=0;i<6;i++){
        ds.make_set(i);
    }
 
    cout<<ds._find(2)<<endl;

    ds._union(0,2);

    cout<<ds._find(2)<<endl;
    ds._union(5,2);

    cout<<ds._find(2)<<endl;
    return 0;
}