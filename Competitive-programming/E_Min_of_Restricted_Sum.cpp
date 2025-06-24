#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Debugging macro
#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#ifdef DEBUG
#define print_vector(v) { cout << #v << " = ["; for (auto &elem : v) cout << elem << " "; cout << "]" << endl; }
#define print_map(m) { cout << #m << " = {"; for (auto &pair : m) cout << "{" << pair.first << ": " << pair.second "} "; cout << "}" << endl; }
#define print_2dvector(v) { cout << #v << " = [" << endl; for (auto &row : v) { cout << "  ["; for (auto &elem : row) cout << elem << " "; cout << "]" << endl; } cout << "]" << endl; }
#else
#define print_vector(v)
#define print_map(m)
#define print_2dvector(v)
#endif

#define endl '\n'
#define int long long
const int INF = 1e18;

// Graph structure
vector<pair<int, int>> graph[200005];
int A[200005];
bool visited[200005];

// Function to minimize the sum by propagating bits
pair<int, int> bfs(int start, int bit) {
    queue<int> q;
    q.push(start);
    
    A[start] = 0; // Initially assume A[start] = 0
    
    int zero_count = 0;
    int one_count = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (visited[node]) continue;
        visited[node] = true;
        
        // Count the number of 0-bits and 1-bits
        if ((A[node] >> bit) & 1) one_count++;
        else zero_count++;
        
        for (auto it : graph[node]) {
            int v=it.first,z=it.second;
            // Calculate A[v] from A[node] using XOR
            int expected_value = A[node] ^ z;
            
            if (A[v] == -1) {
                A[v] = expected_value;
                q.push(v);
            } else if (A[v] != expected_value) {
                // Contradiction occurred
                return {-1, -1};
            }
        }
    }
    
    // Return the minimum number of set bits
    return {zero_count, one_count};
}

void jarvis() {
    int n, m;
    cin >> n >> m;
    
    // Clear the graph and arrays
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        visited[i] = false;
        A[i] = -1;
    }
    
    // Input edges
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }
    
    // Minimum sum calculation
    int min_sum = 0;
    
    // Iterate for each bit from 0 to 29 (since maxA[i] <= 1e9)
    for (int bit = 0; bit < 30; bit++) {
        // Reset visited and A array for bitwise calculation
        for (int i = 1; i <= n; i++) {
            visited[i] = false;
            A[i] = -1;
        }
        
        // Traverse all connected components
        for (int i = 1; i <= n; i++) {
            if (A[i] != -1) continue;
            
            // Try setting the bit as 0 and 1, choose the minimum
            pair<int, int> res1, res2;
            
            // First assume bit=0 at A[1]
            A[i] = 0;
            res1 = bfs(i, bit);
            
            // Reset and try bit=1
            for (int j = 1; j <= n; j++) {
                visited[j] = false;
                A[j] = -1;
            }
            A[i] = (1LL << bit);
            res2 = bfs(i, bit);
            
            // If both are invalid, answer is -1
            if (res1.first == -1 && res2.first == -1) {
                cout << -1 << endl;
                return;
            }
            
            // Count the minimum number of 1-bits for this bit
            int min_bit_cost = INF;
            if (res1.first != -1) 
                min_bit_cost = min(min_bit_cost, res1.second);
            if (res2.first != -1)
                min_bit_cost = min(min_bit_cost, res2.first);
            
            // Add the minimum bit contribution
            min_sum += min_bit_cost * (1LL << bit);
        }
    }
    
    cout << min_sum << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q = 1;
    // cin >> q;
    while (q--)
    {
        jarvis();
    }
    return 0;
}
