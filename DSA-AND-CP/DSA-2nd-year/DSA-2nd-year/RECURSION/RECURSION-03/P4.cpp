#include <bits/stdc++.h>
using namespace std;
// skip a character--------important concept
// inefficient method
void skip_a_char(string original, string ex)
{
    if (original.size() == 0)
    {
        cout << ex;
        return;
    }
    char ch = original[0];
    if (ch == 'h')
        skip_a_char(original.substr(1), ex);
    else
        skip_a_char(original.substr(1), ex + ch);
}
void skip_a_char(string original, string ex, int idx)
{
    if (idx == original.size())
    {
        cout << ex;
        return;
    }
    char ch = original[idx];
    if (ch == 'h')
        skip_a_char(original, ex, idx + 1);
    else
        skip_a_char(original, ex + ch, idx + 1);
}
int main()
{
    string s = "halmet hello";
    skip_a_char(s, "");
    cout << endl;
    skip_a_char(s, "", 0);
    return 0;
}