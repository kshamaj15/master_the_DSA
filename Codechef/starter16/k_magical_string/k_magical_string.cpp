#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int q;
    cin >> q;
    while (q--) {
      bool gotAns = false;
      int l, r, k;
      cin >> l >> r >> k;
      int newl = r - l + 1;
      string sub = s.substr(l - 1, newl);
      sort(sub.begin(), sub.end());
      string ans = sub.substr(0, k);
      if (ans.size() > 0 && sub.size() > k && ans[0] == sub[k]) {
        cout << "No\n";
        gotAns = true;
      } else if(sub.size() > k) {
        for (int i = k; i < newl; i++) {
          ans = sub[i] + ans;
        }
      }
      if (!gotAns) {
        cout << "Yes\n";
        cout << ans << "\n";
      }
    }
  }
  return 0;
}