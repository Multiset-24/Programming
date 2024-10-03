#include <bits/stdc++.h>
using namespace std;
//meeting room II

int meeting_room(vector<vector<int>>&meeting_timing){
    vector<int>start;
    vector<int>end;
    for(int i=0;i<meeting_timing.size();i++){
        start.push_back(meeting_timing[i][0]);
        end.push_back(meeting_timing[i][1]);
    }
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());

    int ans=0;
    int rooms=0;
    int i=0;
    int j=0;


    while(i<start.size() && j<end.size()){
        if(start[i]<end[j]){
            rooms++;
            ans=max(ans,rooms);
            i++;
        }
        else if(start[i]>end[j]){
            rooms--;
            j++;
        }
        else{
            j++;
            i++;
        }
    }
    return ans;
}
int main() {
    vector<vector<int>>meeting_timing={
        {1,2},
        {3,4},
        {7,10},
        {4,5},
        {5,9}
    };

    cout<<meeting_room(meeting_timing);
    return 0;
}