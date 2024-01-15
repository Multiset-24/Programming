#include <bits/stdc++.h>
using namespace std;

//rabbits in a forest

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int min_count=0;
        unordered_map<int,int>mp;
        min_count+=answers[0]+1;
        mp[answers[0]]=answers[0]+1;
        for(int i=1;i<answers.size();i++){
            if(mp.find(answers[i])==mp.end() || mp[answers[i]]==0){
                mp[answers[i]]=answers[i]+1;
                min_count+=answers[i]+1;
            }
            else{
             mp[answers[i]]--;
            }
            if(mp[answers[i]]==0){
                mp[answers[i]]=answers[i]+1;
                min_count+=answers[i]+1;
            }
        }
        return min_count;
    }
};
int main() {
 
    return 0;
}