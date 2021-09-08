// https://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition/

#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

void helper(vector<int> &A, int sum, vector<int> &comb,
                           vector<vector<int>> &ans, int index) {
  if (sum == 0) {
    ans.push_back(comb);
    return;
  }

  if (index == A.size()) {
    return;
  }

  if (A[index] <= sum) {
    comb.push_back(A[index]);
    helper(A, sum - A[index], comb, ans, index);
    comb.pop_back();
  }
  helper(A, sum, comb, ans, index + 1);
}

vector<vector<int>> combinationSum(vector<int> &A, int B) {
  vector<int> comb;
  vector<vector<int>> ans;
  sort(A.begin(), A.end());
  vector<int> uni;
  uni.push_back(A[0]);
  int prev = A[0];
  for(int i=1; i<A.size(); i++){
      if(A[i] != prev){
        uni.push_back(A[i]);
        prev = A[i];
      }
  }

  helper(uni, B, comb, ans, 0);
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int sum;
    cin >> sum;
    vector<vector<int>> ans = combinationSum(arr, sum);
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
  }
}
