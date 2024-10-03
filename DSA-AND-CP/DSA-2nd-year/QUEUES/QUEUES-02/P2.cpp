#include <bits/stdc++.h>
using namespace std;
//first negative in each window of size k
vector<int>firstnegative(vector<int>&number,int k){
    int n=number.size();
    vector<int>ans;
    queue<int>q;
    for (int i = 0; i < n; i++)
    {
        if(number[i]<0) q.push(i);
    }
    int i=0;
    while(i+k<n ){
        if(q.front()<i) q.pop();
        else if(q.front()<i+k&&q.front()>=i){
            ans.push_back(number[q.front()]);
            i++;
        }
        else if(q.front()>=i+k){
            i++;
            ans.push_back(69);
        }
    }
    return ans;
}
int main() {
    vector<int>number={0,-1,-2,-5,4,-5,6,4,7,-8};
    number=firstnegative(number,3);
    for (int i = 0; i < number.size(); i++)
    {
        cout<<number[i]<<" ";
    }
    
    return 0;
}