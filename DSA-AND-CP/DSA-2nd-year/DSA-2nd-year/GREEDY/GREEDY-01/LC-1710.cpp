#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int>a,vector<int>b){
    return a[1]>b[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int max=0;

        for(int i=0;i<boxTypes.size();i++){
            if(boxTypes[i][0]<=truckSize){
                max+=(boxTypes[i][0]*boxTypes[i][1]);
                truckSize-=boxTypes[i][0];
            }
            else{
                max+=(truckSize*boxTypes[i][1]);
                truckSize=0;
            }
        }
        return max;
    }
};
int main() {
 
    return 0;
}