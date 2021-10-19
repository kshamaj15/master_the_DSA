// https://www.codechef.com/SNCKQL21/problems/MAXDISTKT

#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

bool mycompare(pair<int, int> p1, pair<int, int> p2) {
  return p1.second < p2.second;
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
    int arr[n];
    vector<int> ans(n);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      pair<int, int> p = make_pair(i, arr[i]);
      v.push_back(p);
    }
    sort(v.begin(), v.end(), mycompare);
    int rem = 0;
    for (int i = 0; i < n; i++) {
      if (rem < v[i].second) {
        ans[v[i].first] = v[i].second + rem;
        rem++;
      } else {
        ans[v[i].first] = v[i].second+ rem - 1;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
}
