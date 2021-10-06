#include <bits/stdc++.h>
#include <cmath>
using namespace std;

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
    int base = floor(log(n) / log(2));
    int val = pow(2, base);
    cout << max(val / 2, n - val + 1)<<"\n";
  }
}
