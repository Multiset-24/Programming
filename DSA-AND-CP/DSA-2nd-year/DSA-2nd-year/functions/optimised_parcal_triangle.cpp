// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin>>n;
//     for (int i = 0; i<n ; i++)
//     {  
//         int curr=1;
//        for (int j =0; j<=i ; j++)
//        {
//         if(i==j){
//         cout<<"1"<<" ";
//         }
//        else {
//         cout<<curr<<" ";
//         curr=curr*(float(i-j)/(j+1));
//        }
//        }
//        cout<<endl;
//        }
//     return 0;
//     }
#include <iostream>

void printPascalsTriangle(int n) {
    for (int line = 1; line <= n; ++line) {
        int coefficient = 1;
        for (int j = 1; j <= line; ++j) {
            std::cout << coefficient << " ";
            coefficient = coefficient * (line - j) / j;
        }
        std::cout << std::endl;
    }
}

int main() {
    int num_rows;
    std::cout << "Enter the number of rows: ";
    std::cin >> num_rows;
    printPascalsTriangle(num_rows);
    return 0;
}

    
