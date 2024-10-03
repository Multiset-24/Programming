#include <iostream>
using namespace std;

int countWays(int n) {
    if (n <= 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
}
void printreverseprint(int n){
    cout<<n;
    if(n==1) return;
    printreverseprint(n-1);
    cout<<n;
}

int main() {    
    using namespace std;
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    int ways = countWays(n);
    cout << "The number of ways to climb " << n << " stairs is: " << ways << endl;

printreverseprint(n);
    return 0;
}
