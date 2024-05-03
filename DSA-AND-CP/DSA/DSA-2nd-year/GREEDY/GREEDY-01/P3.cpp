#include <bits/stdc++.h>
using namespace std;
//minimum cost to cut a board into square
 int minimum_cost(vector<int>&length,vector<int>&width){
        sort(length.begin(),length.end(),greater<int>());
        sort(width.begin(),width.end(),greater<int>());

        int ans=0;
        int Hb=1;
        int Vb=1;
        for(int i=0;i<max(length.size(),width.size());i++){
            if(i<length.size()){
                ans+=Hb*length[i];
                Vb++;
            }
            if(i<width.size()){
                ans+=Vb*width[i];
                Hb++;
            }
        }
        return ans;
 }
int main() {
    vector<int>length={2,1,3,1,4};
    vector<int>width={4,1,3};
    cout<<minimum_cost(length,width);
    return 0;
}