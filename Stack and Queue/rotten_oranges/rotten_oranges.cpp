// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool rot(vector<vector<int>> &grid, int x, int y, queue<pair<int, int>> &qu) {
  int left = y-1;
  int right = y+1;
  int up = x-1;
  int down = x+1;
  int row = grid.size();
  int col = grid[0].size();

  bool isAnytoRot = false;

  if (left >= 0 && grid[x][left] == 1) {
    pair<int, int> p = make_pair(x, left);
    qu.push(p);
    grid[x][left] = 2;
    isAnytoRot = true;
  }
  if (up >= 0 && grid[up][y] == 1) {
    pair<int, int> p = make_pair(up, y);
    qu.push(p);
    grid[up][y] = 2;
    isAnytoRot = true;
  }
  if (right < col && grid[x][right] == 1) {
    pair<int, int> p = make_pair(x, right);
    qu.push(p);
    grid[x][right] = 2;
    isAnytoRot = true;
  }
  if (down < row && grid[down][y] == 1) {
    pair<int, int> p = make_pair(down, y);
    qu.push(p);
    grid[down][y] = 2;
    isAnytoRot = true;
  }
  return isAnytoRot;
}
int orangesRotting(vector<vector<int>> &grid) {
  int row = grid.size();
  int col = grid[0].size();

  queue<pair<int, int>> qu;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (grid[i][j] == 2) {
        pair<int, int> p = make_pair(i, j);
        qu.push(p);
      }
    }
  }

  int timeF = 0;
  int len = qu.size();
  while (!qu.empty()) {
    bool isAnytoRot = false;
    while (!qu.empty() && len--) {
      int x = qu.front().first;
      int y = qu.front().second;
      isAnytoRot = rot(grid, x, y, qu) | isAnytoRot;
      qu.pop();
    }
    len = qu.size();
    if (isAnytoRot)
      timeF++;
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (grid[i][j] == 1) {
        return -1;
      }
    }
  }
  return timeF;
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
    cout << orangesRotting(grid) << endl;
  }
}
