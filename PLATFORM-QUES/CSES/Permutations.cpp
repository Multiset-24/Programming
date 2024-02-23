#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
vector<int> permutations(int  n){
    vector<int>beautiful_num;
    vector<bool>visited(n+1,false);
    
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            beautiful_num.push_back(i);
            visited[i]=true;
        }
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            beautiful_num.push_back(i);
        }
    }

    return beautiful_num;
}
int main() {
    int n;
    cin>>n;

    vector<int>sundar_ank=permutations(n);
    if(n==3 || n==2){
        cout<<"NO SOLUTION";
        return 0;;
    }

    if(n==4){
        cout<<2<<" "<<4<<" "<<1<<" "<<3;
        return 0;
    }
    for(int i=sundar_ank.size()-1;i>=0;i--){
        cout<<sundar_ank[i]<<" ";
    }
    return 0;
}