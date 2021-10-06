#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a > 0 && b > 0)
      cout << "Solution\n";
    if (a == 0)
      cout << "Liquid\n";
    if (b == 0)
      cout << "Solid\n";
  }
}
