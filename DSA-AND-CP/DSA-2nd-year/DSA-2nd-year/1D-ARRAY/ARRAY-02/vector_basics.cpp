#include <bits/stdc++.h>
using namespace std;

int main() {
 vector<int>v;
//  v[0]=5; this is not allowed since till this step capacity of vecotr is 0
 v.push_back(4);
v.push_back(3);
v.push_back(44);
cout<<v.capacity();
v.pop_back();
cout<<v.size()<<" "<<v.capacity();
    return 0;
}