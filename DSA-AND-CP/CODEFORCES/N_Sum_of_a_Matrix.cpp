#include <iostream>
#include <vector>
using namespace std;

void sumMatricesRecursively(const vector<vector<int>>& a, const vector<vector<int>>& b, vector<vector<int>>& result, int r, int c, int i, int j) {
    // Base case: If indices are out of bounds, return.
    // if (i >= r || j >= c) return;

    // Add the current elements of both matrices.
    result[i][j] = a[i][j] + b[i][j];

    // Move to the next column
    if (j + 1 < c) {
        sumMatricesRecursively(a, b, result, r, c, i, j + 1);
    } else if (i + 1 < r) { // Move to the next row if we've reached the end of the current row
        sumMatricesRecursively(a, b, result, r, c, i + 1, 0);
    }
}

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> a(r, vector<int>(c));
    vector<vector<int>> b(r, vector<int>(c));
    vector<vector<int>> result(r, vector<int>(c, 0));

    // Input for matrix a
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    // Input for matrix b
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> b[i][j];
        }
    }

    // Perform the sum using recursion
    sumMatricesRecursively(a, b, result, r, c, 0, 0);

    // Print the result
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}