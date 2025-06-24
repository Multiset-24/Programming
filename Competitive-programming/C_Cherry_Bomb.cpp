#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,k,minimum,maximum; cin>>n>>k;
    int a[n],b[n];
    bool is_comp=true;
   
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i){
            minimum=min(a[i],minimum);
            maximum=max(a[i],maximum);
        }else{
            minimum=maximum=a[i];
        }
    }
    for(int i=0;i<n;i++)cin>>b[i];
 
    int arr_sum,result=0;
    bool ch=true;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]>=0 && b[i]>=0){
            if(ch){
                arr_sum=a[i]+b[i];
                ch=false;
                cnt++;
            }
            else{
                if(a[i]+b[i]!=arr_sum){is_comp=false;}
                else cnt++;
            }
        }
    }
    if(is_comp==true && cnt==n){
        cout<<1<<endl;
        return;
    };
    if(is_comp){
        if(!ch){
            result=1;
            for(int i=0;i<n;i++){
                if(arr_sum-a[i]<0){result=0;break;}
                else if(arr_sum-a[i]>k){result=0;break;}
            }
        }
        // if(!ch && arr_sum<maximum)result=0;
        // else if(!ch && arr_sum>k+minimum)result=0;
        // else if(!ch && arr_sum>k)result=0;
        // else if(!ch && arr_sum<=k)result=1;
        else if(ch)result=(minimum+k)-maximum+1;
    }
    cout<<result<<'\n';
    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}