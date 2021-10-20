#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool isPossible(vector<int> &arr, int n) {
    for (int i=0; i<n; i++) {
        if(arr[i] < i) return false;
    }
    return true;
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
    string s = isPossible(arr, n) ? "Yes" : "No";
    cout << s << endl;
  }
}
