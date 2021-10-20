#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <string>

using namespace std;

// vector<int> solve(int n, int m, vector<vector<int>> a, int q, int s,
//                   vector<vector<long long>> queries) {
//   vector<int> ans;
//   vector<int> sums;
//   for (int i = 0; i < n; i++) {
//     int sum = 0;
//     for (int j = 0; j < m; j++) {
//       sum += a[i][j];
//     }
//     sums.push_back(sum);
//   }
//   for (int i = 0; i < m; i++) {
//     int sum = 0;
//     for (int j = 0; j < n; j++) {
//       sum += a[j][i];
//     }
//     sums.push_back(sum);
//   }
//   sort(sums.begin(), sums.end());

//   for (int i = 0; i < q; i++) {
//     int l = queries[i][0];
//     int r = queries[i][1];

//     int count = 0;

//     for (int j = 0; j < n + m; j++) {
//       if (sums[j] >= l && sums[j] <= r) {
//         count++;
//       }
//     }
//     ans.push_back(count);
//   }
//   return ans;
// }
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  string str;
  int n;
  cin >> str >> n;
  string ans;
  int ac = 0, bc = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'a')
      ac++;
    else if (str[i] == 'b')
      bc++;
    if (ac == n) {
      ans = "Team A won";
      break;
    }
    if (bc == n) {
      ans = "Team B won";
      break;
    }
  }
  if (ac < n && bc < n) {
    int as = 0, bs = 0;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == 'a')
        as++;
      else if (str[i] == 'b')
        bs++;
      if (as - bs == 2) {
        ans = "Team A won";
        break;

      }
      if (as - bs == -2) {
        ans = "Team B won";
        break;
      }
    }
  }
  cout<<ans;
}
