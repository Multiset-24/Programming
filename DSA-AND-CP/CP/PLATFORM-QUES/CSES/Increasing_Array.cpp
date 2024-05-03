#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
ll increasing_array(vector<int>&num){
    ll min_move=0;

    for(int i=1;i<num.size();i++){
        if(num[i]<num[i-1]){
            min_move+=(num[i-1]-num[i]);
            cout<<num[i]<<' ';

        }
    }
    
    return min_move;
}
int main() {
    int n;
    cin>>n;

    vector<int>num(n);

    for(int i=0;i<n;i++) cin>>num[i];
    
    cout<<increasing_array(num);
    return 0;
}