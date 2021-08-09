// https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSafe(int grid[9][9], int n, int r, int c) {
  for (int i = 0; i < 9; i++) {
    if (grid[r][i] == n || grid[i][c] == n)
      return false;
  }
  int r1 = (r / 3) * 3;
  int c1 = (c / 3) * 3;
  int r2 = r1 + 2;
  int c2 = c1 + 2;

  for (int i = r1; i <= r2; i++) {
    for (int j = c1; j <= c2; j++) {
      if (grid[i][j] == n)
        return false;
    }
  }
  return true;
}

vector<int> getNextCo(int grid[9][9], int row, int col) {
  vector<int> v;
  for (int i = col; i < 9; i++) {
    if (grid[row][i] == 0) {
      v.push_back(row);
      v.push_back(i);
      return v;
    }
  }
  for (int i = row + 1; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (grid[i][j] == 0) {
        v.push_back(i);
        v.push_back(j);
        return v;
      }
    }
  }
  return v;
}

// Function to print grids of the Sudoku.
void printGrid(int grid[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  cout<<endl;
}

int getSolvedSoluku(int grid[9][9], int row, int col) {
  vector<int> nxt = getNextCo(grid, row, col);
  if (nxt.size() == 0) {
    return 1;
  }
  for (int i = 1; i < 10; i++) {
    if (isSafe(grid, i, nxt[0], nxt[1])) {
      grid[nxt[0]][nxt[1]] = i;
      if (getSolvedSoluku(grid, nxt[0], nxt[1]))
        return 1;
    }
  }
  grid[nxt[0]][nxt[1]] = 0;
  return 0;
}

// Function to find a solved Sudoku.
bool SolveSudoku(int grid[9][9]) {
  // Your code here
  return getSolvedSoluku(grid, 0, 0);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t;
  cin >> t;
  while (t--) {
    int grid[9][9];
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cin >> grid[i][j];
      }
    }

    if (SolveSudoku(grid)) {
      printGrid(grid);
    } else {
      cout << "No result found";
    }
  }
}
