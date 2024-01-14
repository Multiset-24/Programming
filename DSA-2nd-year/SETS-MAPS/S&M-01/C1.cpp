#include <iostream>
using namespace std;
#include<unordered_set>
//stl in unordered sets
int main() {
    unordered_set<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(0);
    s.insert(0);//only inset unique element
    // s.erase(4);
    for(int ele:s){
        cout<<ele<<" ";
    }
    cout<<endl;
    if(s.find(9)!=s.end()){
        cout<<"exists"<<endl;
    }
    else cout<<"does not exists";
    cout<<s.size();
    return 0;
}