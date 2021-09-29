// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1#
#include <bits/stdc++.h>
#include <iostream>
#include <ostream>

using namespace std;

void cover(vector<vector<int>> grid, vector<vector<int>> &ans,
           pair<int, int> p, queue<pair<int, int>> &qu, int dist) {
  int x = p.first;
  int y = p.second;
  int left = y - 1;
  int right = y + 1;
  int up = x - 1;
  int down = x + 1;
  int row = grid.size();
  int col = grid[0].size();

// cout<<x<<" "<<y<<endl;
// cout<<x<<" "<<right<<" "<<col<<endl;

  if (left >= 0 && ans[x][left] == -1) {
// cout<<"l "<<x<<" "<<left<<endl;
    pair<int, int> p = make_pair(x, left);
    qu.push(p);
    ans[x][left] = dist;
  }
  if (up >= 0 && ans[up][y] == -1) {
// cout<<"u "<<up<<" "<<y<<endl;
    pair<int, int> p = make_pair(up, y);
    qu.push(p);
    ans[up][y] = dist;
  }
//   cout<<"djsdk "<<right<<col<<grid[x][right]<<endl;
  if (right < col && ans[x][right] == -1) {
// cout<<"r "<<x<<" "<<right<<endl;
    pair<int, int> p = make_pair(x, right);
    qu.push(p);
    ans[x][right] = dist;
  }
  if (down < row && ans[down][y]  == -1) {
// cout<<"d "<<down<<" "<<y<<endl;
    pair<int, int> p = make_pair(down, y);
    qu.push(p);
    ans[down][y] = dist;
  }
}

vector<vector<int>> nearest(vector<vector<int>> grid) {
  int row = grid.size();
  int col = grid[0].size();
  vector<vector<int>> ans(row, vector<int>(col, -1));
  vector<vector<bool>> visit(row, vector<bool>(col, false));
  queue<pair<int, int>> qu;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (grid[i][j]) {
        pair<int, int> p = make_pair(i, j);
        qu.push(p);
        ans[i][j] = 0;
      }
    }
  }

  int len = qu.size();
  int val = 1;
  while (!qu.empty()) {
    while (!qu.empty() && len--) {
      if(!visit[qu.front().first][qu.front().second])
       cover(grid, ans, qu.front(), qu, val);
      visit[qu.front().first][qu.front().second] = true;
      qu.pop();
    }
    val++;
    len = qu.size();
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
    int row, col;
    cin >> row >> col;
    vector<vector<int>> grid(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        cin >> grid[i][j];
      }
    }
    vector<vector<int>> ans = nearest(grid);
    for (auto el : ans) {
      for (auto e : el) {
        cout << e << " ";
      }
      cout << endl;
    }
  }
}
