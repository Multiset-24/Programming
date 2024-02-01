#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define F(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)

int main() {
    int n;
    cin>>n;

    vector<int>soldier(n);

    F(i,0,n-1){
        cin>>soldier[i];
    }
    int minm=INT_MAX;
    int maxm=INT_MIN;

    int min_idx=0;
    int max_idx=0;
    F(i,0,n-1){
        if(maxm<soldier[i]){
            maxm=soldier[i];
            max_idx=i;
        }
    }

    int min_time=0;
    while(max_idx!=0){
        min_time++;
        swap(soldier[max_idx],soldier[max_idx-1]);
        max_idx--;
    }
    RF(i,n-1,0){
        if(minm>soldier[i]){
            minm=soldier[i];
            min_idx=i;
        }
    }

    while(min_idx!=n-1){
        swap(soldier[min_idx],soldier[min_idx+1]);
        min_idx++;
        min_time++;
    }

    cout<<min_time;
    return 0;
}