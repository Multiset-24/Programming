#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */
class dsu
{
public:
    int n;
    vector<int> parent;
    vector<int> rank;

    dsu(int size)
    {
        n = size;
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        else
             return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        int a = find(x);
        int b = find(y);

        if (a != b)
        {
            if (rank[a] > rank[b])
            {
                parent[b] = a;
            }
            else if (rank[a] < rank[b])
            {
                parent[a] = b;
            }
            else
            {
                parent[a] = b;
                rank[b]++;
            }
        }
    }

    vector<int> getGroupSizes()
    {
        vector<int> sizes(n, 0);
        for (int i = 0; i < n; i++)
        {
            int root = find(i);
            sizes[root]++;
        }
        return sizes;
    }
};
long long journeyToMoon(int n, vector<vector<int>> astronaut) {
        
        int k=astronaut.size();

        dsu groups(n);

        for (int i = 0; i < k; i++)
        {
            int x, y;
            x=astronaut[i][0];
            y=astronaut[i][1];

            groups.unite(x, y);
        }
    
        vector<int>group_sizes = groups.getGroupSizes();

        long long ans=0;

        vector<int>suffix_sum(group_sizes.size()+1,0);

        for(int i=group_sizes.size()-1;i>=0;i--){
            suffix_sum[i]+=(group_sizes[i]+suffix_sum[i+1]);
        }

        for(int i=1;i<group_sizes.size();i++){
            ans+=(suffix_sum[i]*group_sizes[i-1]);
        }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    long long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
