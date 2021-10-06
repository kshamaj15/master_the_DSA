#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
  return abs(p1.first - p1.second) > abs(p2.first - p2.second);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  vector<int> b(n);
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int profit = 0;
  for (int i = 0; i < n; i++) {
    pair<int, int> p = make_pair(a[i], b[i]);
    v.push_back(p);
  }
  int xc = 0, yc = 0;
  sort(v.begin(), v.end(), compare);
  for (int i = 0; i < n; i++) {
    cout << v[i].first << " " << v[i].second << endl;
    if (v[i].first > v[i].second && xc < x) {
      xc++;
      profit += v[i].first;
    } else if (v[i].first < v[i].second && yc < y) {
      yc++;
      profit += v[i].second;
    } else if (yc >= y)
      profit += v[i].first;
    else if (xc >= x)
      profit += v[i].second;
  }
  cout << profit;

  return 0;
}