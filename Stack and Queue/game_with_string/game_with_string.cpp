// https://leetcode.com/problems/merge-intervals/

#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int minValue(string s, int k) {
  vector<int> alpha(26);
  priority_queue<int> pq;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    int index = s[i] - 'a';
    alpha[index]++;
  }
  for (int i = 0; i < 26; i++) {
    pq.push(alpha[i]);
  }
  while (k--) {
    int newv = pq.top() - 1;
    pq.pop();
    pq.push(newv);
  }
  while (!pq.empty()) {
    ans += pq.top() * pq.top();
    pq.pop();
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
    int k;
    cin >> k;
    cout << minValue(str, k) << endl;
  }
}
