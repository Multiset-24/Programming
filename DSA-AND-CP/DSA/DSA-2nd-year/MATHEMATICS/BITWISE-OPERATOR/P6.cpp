#include <bits/stdc++.h>
using namespace std;
//given an integer array where every element occurs twice except one occursi only once find that unique element.

int find_unique_element(vector<int>v){
    int res=0;
    for (int i = 0; i <v.size() ; i++)
    {
        res=res^v[i];
    }
    return res;
}
int main() {
    vector<int>v={1,3,3,4,2,1,2,9,100,4,9};
    cout<<find_unique_element(v);
    return 0;
}