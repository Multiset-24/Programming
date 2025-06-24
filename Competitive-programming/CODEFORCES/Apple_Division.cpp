#include <bits/stdc++.h>
using namespace std;
#define int long long 

int ans=INT_MAX;
void findMinDifference(vector<int>&v,int i,int sumCalculated,int totalSum){
    if(i==v.size()){
        ans=min(ans,abs(totalSum-2*sumCalculated));
        return;
    }

    //include
    findMinDifference(v,i+1,sumCalculated+v[i],totalSum);
    
    //exclude
    findMinDifference(v,i+1,sumCalculated,totalSum);

    return ;
}

void jarvis() {
    int n;
    cin >> n;
    vector<int> v(n);
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        totalSum += v[i];
    }
    findMinDifference(v, 0, 0, totalSum) ;
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    jarvis();
    return 0;
}