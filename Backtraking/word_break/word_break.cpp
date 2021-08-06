// https://practice.geeksforgeeks.org/problems/word-break-part-23249/1

#include <bits/stdc++.h>
using namespace std;

bool isValidWord(vector<string> &dict, string word) {
  for (int i = 0; i < dict.size(); i++) {
    if (dict[i] == word)
      return true;
  }
  return false;
}

void getSentences(int n, vector<string> &dict, string s, int i2, string str,
                  vector<string> &ans) {
  if (i2 == s.length()) {
    str = str.substr(0, str.length() - 1);
    ans.push_back(str);
    return;
  }
  string word;
  for (int i = i2; i < s.length(); i++) {
    word = s.substr(i2, i - i2 + 1);
    if (isValidWord(dict, word)) {
      str += (word + ' ');
      getSentences(n, dict, s, i + 1, str, ans);
      str = str.substr(0, str.length() - word.length() - 1);
    }
  }
}

vector<string> wordBreak(int n, vector<string> &dict, string s) {
  vector<string> ans;
  string str = "";
  getSentences(n, dict, s, 0, str, ans);
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  
  while (t--) {
    int n;
    cin >> n;
    string s;
    vector<string> dist;
    // vector<string> ans;
    for (int i = 0; i < n; i++) {
      cin >> s;
      dist.push_back(s);
    }
    cin >> s;

    vector<string> ans = wordBreak(n, dist, s);

    if (ans.size()) {
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
      }
      cout << endl;
    } else {
      cout << "No result found" << endl;
    }
  }
}
