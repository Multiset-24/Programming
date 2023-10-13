#include <bits/stdc++.h>
using namespace std;
#include <sstream>
bool anagram(string s, string t)
{
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  if (s == t)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void freq_no_M1(string s)
{
  int max_count = INT_MIN;
  for (int i = 0; i < s.size(); i++)
  {
    int count = 1;
    for (int j = i + 1; j < s.size(); j++)
    {
      if (s[i] == s[j])
      {
        count++;
      }
    }
    if (count > max_count)
    {
      max_count = count;
    }
  }
  cout << max_count;
}
void freq_no_M2(string s)
{
  vector<int> alpha(26, 0);
  for (int i = 0; i < s.length(); i++)
  {
    char ch = s[i];
    int ascii = int(ch);
    alpha[ascii - 97]++;
  }

  int mx = 0;
  for (int i = 0; i < 26; i++)
  {
    if (alpha[i] > mx)
      mx = alpha[i];
  }
  for (int i = 0; i < 26; i++)
  {
    if (alpha[i] == mx)
    {
      int ascii = i + 97;
      char ch = (char)ascii;
      cout << ch << " " << mx << endl;
    }
  }
}
void WoSl(string s)
{
  stringstream san(s);
  string temp;
  while (san >> temp)
  {
    cout << temp << endl;
  }
}
void NoRW(string s)
{
  vector<string> v;
  string temp;
  stringstream ss(s);
  while (ss >> temp)
  {
    v.push_back(temp);
  }
  sort(v.begin(), v.end());
  int count = 1;
  int max_count = 1;
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] == v[i + 1])
    {
      count++;
    }
    else
    {
      count = 1;
    }
    max_count = max(max_count, count);
  }
  count = 1;
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] == v[i + 1])
    {
      count++;
    }
    else
    {
      count = 1;
    }
    if (count == max_count)
    {
      cout << v[i] << endl;
    }
  }
  cout << max_count;
}
int main()
{
  // P1------------->anagram problem
  string s = "physicswallah";
  string t = "wallahphysics";
  cout << anagram(s, t) << endl;
  // P2------------->most occuring character in a string, method-01
  freq_no_M1(t);
  cout << endl;
  // 2nd method for p2
  freq_no_M2(t);
  cout << endl;
  // P3 print words of a sentence in a seperate line
  string san;
  getline(cin, san);
  WoSl(san);
  cout << endl;
  // P4 number of words which is repeated most of the time
  NoRW(san);
  return 0;
}