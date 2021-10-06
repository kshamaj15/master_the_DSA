#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int m, n;
  cin >> m >> n;
  vector<vector<char>> arr(m, vector<char>(n));
  // vector<vector<char>> ans;
  vector<bool> row(m, false);
  vector<bool> col(n, false);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == '#') {
        row[i] = true;
        col[j] = true;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (row[i]) {
      vector<char> r;
      for (int j = 0; j < n; j++) {
        if (col[j]) {
          cout << arr[i][j] << " ";
        }
      }
      cout << endl;
    }
  }
  return 0;
}