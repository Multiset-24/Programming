#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int,int> pi;
#define u_mp unordered_map 
#define u_st unordered_set 
template<typename T>

// Function templates for reading input
void read(T& t) {
    cin >> t;
}
template<typename T, typename... Args>
void read(T& t, Args&... args) {
    cin >> t;
    read(args...);
}

// Debugging macro
#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

#define endl '\n'

// Binary search using recursion
int binary_search_rec(int i,int j,vector<int>&num,int target){
    int mid=i+(j-i)/2;

    if(i>j){
        return -1;
    }
    
    if(num[mid]==target){
        return mid;
    }
    else return (num[mid]>target)?binary_search_rec(i,mid-1,num,target):binary_search_rec(mid+1,j,num,target);
}

//binary search all stl's

void binary_search_stl(vector<int>&num,int &target){
    cout<<binary_search(num.begin(),num.end(),target)<<endl;//returns 1 if present else 0


    cout<<lower_bound(num.begin(),num.end(),target)-num.begin()<<endl;//returns the index of the first element greater than or equal to target


    cout<<upper_bound(num.begin(),num.end(),target)-num.begin()<<endl;//returns the index of the first element greater than target

   //if there is no element greater than the target element in the array, both lower_bound and upper_bound will return an iterator pointing to the end of the array.
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> num={1,2,3,4,5,6,7,8,9,10};
    int target=3;

    for(int i=0;i<num.size();i++){
        cout<<binary_search_rec(0,num.size()-1,num,num[i])<<endl;
    }
    return 0;
}