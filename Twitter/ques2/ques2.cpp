#include <bits/stdc++.h>

using namespace std;

void diskapce(vector<int> &arr, int n, int x) {
  stack<int> s;
  int l[n + 1];
  int r[n + 1];
  for (int i = 0; i < n; i++) {
    l[i] = -1;
    r[i] = n;
  }
  for (int i = 0; i < n; i++) {
    while (!s.empty() && arr[s.top()] >= arr[i])
      s.pop();
    if (!s.empty())
      l[i] = s.top();
    s.push(i);
  }
  while (!s.empty())
    s.pop();
  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() && arr[s.top()] >= arr[i])
      s.pop();
    if (!s.empty())
      r[i] = s.top();
    s.push(i);
  }
  int ans[n + 1];
  for (int i = 0; i <= n; i++)
    ans[i] = 0;
  for (int i = 0; i < n; i++) {
    int len = r[i] - l[i] - 1;
    ans[len] = max(ans[len], arr[i]);
  }
  for (int i = n - 1; i >= 1; i--)
    ans[i] = max(ans[i], ans[i + 1]);
  int mx = INT_MIN;
  for (int i = 1; i <= n; i++) {
    cout<<ans[i]<<" ";
    mx = max(mx, ans[i]);
  }
  cout << ans[x] << endl;
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
    int x;
    cin>>x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    diskapce(arr, n, x);
  }
  return 0;
}
