#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(a[0]!=a[a.size()-1]) {
            cout<<-1<<endl;
            continue;
        }
        else {
            int ans=INT_MAX;
            int first_different=0;
            for(int i=1;i<n;i++) {
                if(a[i]!=a[0]) {
                    first_different=i;
                    ans=i;
                    break;
                }
            }
            if(ans==INT_MAX) {
                cout<<-1<<endl;
                continue;
            }

            

            for(int i=a.size()-2;i>=0;i--) {
                if(a[i]!=a[0]) {
                    ans=min(ans,(int)a.size()-i-1);
                    break;
                }
            }

            for(int i=first_different+1;i<n;i++) {
                if(a[i]!=a[0]) {
                    ans=min(ans,i-first_different-1);
                    first_different=i;
                }
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}