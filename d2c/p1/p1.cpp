#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int fact(int i) {
  if (i <= 1)
    return 1;
  else
    return i * fact(i - 1);
}

int getTotal(int n, int c, int count, int k) {
  cout<<count<<" "<<n<<endl;
  if (count == k)
    return 1;
  if (n == 0)
    return 0;
  return getTotal(n - 1, c, count + 1, k) + getTotal(n - 1, c, count, k);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n, c, k;
    cin >> n >> c >> k;
    int ans = getTotal(n, c, 0, k);
    cout << fact(c) * ans << endl;
  }
}