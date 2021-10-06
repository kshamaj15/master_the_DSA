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
    int base = floor(log2(n + 1));
    cout << n << " " <<(int)( pow(2, base)) << "\n";
  }
}
