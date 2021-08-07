// https://leetcode.com/problems/remove-invalid-parentheses/
// stack overflow on leetcode
// need to optimise more

#include <bits/stdc++.h>
#include <string>
using namespace std;

bool isValidExp(string s) {
  int open = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(')
      open++;
    else if (s[i] == ')' && open > 0)
      open--;
    else if (s[i] == ')' && open <= 0)
      return false;
  }

  if (!open)
    return true;
  else
    return false;
}

int findNumOfParenthesesToRemove(string s) {
  int num = 0;
  int open = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(')
      open++;
    else if (s[i] == ')' && open > 0)
      open--;
    else if (s[i] == ')' && open <= 0) {
      num++;
      open = 0;
    }
  }
  return num + open;
}

void getNextVal(int n, int validSize, string s, int sIndex, int strIndex,
                string str, vector<string> &ans) {
  if (strIndex == validSize) {
    if (isValidExp(str) && (!ans.size() || ans[ans.size() - 1] != str)) {
      ans.push_back(str);
    }
    return;
  }

  if (strIndex > validSize || sIndex >= n)
    return;

  while (s[sIndex] != '(' && s[sIndex] != ')') {
    str += s[sIndex];
    sIndex++;
    strIndex++;
  }
  getNextVal(n, validSize, s, sIndex + 1, strIndex, str, ans);
  getNextVal(n, validSize, s, sIndex + 1, strIndex + 1, str + s[sIndex], ans);
}

vector<string> removeInvalidParentheses(string s) {
  vector<string> ans;
  string str = "";
  int n = s.size();
  int validSize = n - findNumOfParenthesesToRemove(s);
  getNextVal(n, validSize, s, 0, 0, str, ans);
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
    string s;
    cin >> s;

    vector<string> ans = removeInvalidParentheses(s);

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
