#include <bits/stdc++.h>
using namespace std;

void jarvis(){
   int x;
   cin>>x;
   
   vector<bool>isprime(100005,true);
   isprime[0]=false;
   isprime[1]=false;
   
   for(int i=2;i*i<=100005;i++){
     if(isprime[i]){
       for(int j=i*i;j<=100005;j+=i){
         isprime[j]=false;
       }
     }
   }
   
   while(isprime[x]==false){
    x++;
   }

   cout<<x<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    int q=1;
    // cin>>q;
    while(q--){
        jarvis();
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cerr << "Time taken: " << duration.count() << " microseconds" << endl;
    return 0;
}

