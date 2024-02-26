#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Upper half of the diamond
    for (int i = 0; i <= n; i++) {
        // Print spaces before the digits
        for (int j = 0; j < abs(n - i); j++)
            cout << "  ";

        // Print increasing digits without gaps
        for (int j = 0; j <= i; j++) {
            cout << j;
            if (j < i) cout << " ";
        }

        cout << endl;
    }

    // Lower half of the diamond (mirrored)
    for (int i = n - 1; i >= 0; i--) {
        // Print spaces before the digits
        for (int j = 0; j < abs(n - i); j++)
            cout << "  ";

        // Print increasing digits without gaps
        for (int j = 0; j <= i; j++) {
            cout << j;
            if (j < i) cout << " ";
        }

        cout << endl;
    }

    return 0;
}
