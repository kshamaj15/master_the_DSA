// https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

bool braces(string str) {
  stack<int> s;
  int start = 0, end = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '(') {
      s.push(i);
    } else if (str[i] == ')') {
      if (i - s.top() <= 2)
        return true;
      else {
        if (start - s.top() == 1 && i - end == 1)
          return true;
        start = s.top();
        end = i;
        s.pop();
      }
    }
  }
  return false;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    cout << braces(str) << endl;
  }
}
