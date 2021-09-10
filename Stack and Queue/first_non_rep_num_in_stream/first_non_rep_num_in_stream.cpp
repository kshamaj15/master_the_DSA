// https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

string FirstNonRepeating(string A) {
  queue<int> qu;
  string ans = "";
  unordered_map<char, int> mp;
  for (int i = 0; i < A.size(); i++) {
    if (mp[A[i]] == 0)
      qu.push(A[i]);
    mp[A[i]]++;
    while (!qu.empty() && mp[qu.front()] != 1) {
      qu.pop();
    }
    if (qu.empty())
      ans += '#';
    else
      ans += qu.front();
  }
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
    string str;
    cin >> str;
    cout << FirstNonRepeating(str) << endl;
  }
}
