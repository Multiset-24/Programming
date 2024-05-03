#include <bits/stdc++.h>
using namespace std;

template<typename T>
void read(T& t) {
    cin >> t;
}
template<typename T, typename... Args>
void read(T& t, Args&... args) {
    cin >> t;
    read(args...);
}

int main() {
    int num_elements, num_queries;
    read(num_elements, num_queries);

    set<int> elements;
    for(int i = 0; i < num_elements; i++) {
        int x;
        read(x);
        elements.insert(x);
    }

    while(num_queries--){
        int x;
        read(x);
        auto it = elements.lower_bound(x);

        int num_less = distance(elements.begin(), it);
        int num_greater = distance(it, elements.end());

        // If x is in the set, it is not greater than x
        if (it != elements.end() && *it == x) {
            num_greater--;
        }

        cout << num_less << " " << num_greater << endl;
    }
    return 0;
}