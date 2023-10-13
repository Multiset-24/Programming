#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;

    cout << "Initial size: " << v.size() << endl;
    cout << "Initial capacity: " << v.capacity() << endl;

    v.push_back(6);
    cout << "Size after adding 6: " << v.size() << endl;
    cout << "Capacity after adding 6: " << v.capacity() << endl;

    v.push_back(3);
    cout << "Size after adding 3: " << v.size() << endl;
    cout << "Capacity after adding 3: " << v.capacity() << endl;

    v.push_back(6);
    cout << "Size after adding another 6: " << v.size() << endl;
    cout << "Capacity after adding another 6: " << v.capacity() << endl;

    v.push_back(7);
    cout << "Size after adding 7: " << v.size() << endl;
    cout << "Capacity after adding 7: " << v.capacity() << endl;

    v.push_back(9);
    cout << "Size after adding 9: " << v.size() << endl;
    cout << "Capacity after adding 9: " << v.capacity() << endl;

    return 0;
}
