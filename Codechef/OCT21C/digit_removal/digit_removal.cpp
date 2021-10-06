#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    int div = 1;
    int ans = 0;
    if (n == 0) {
      if (d == 0)
        ans = 1;
      cout << ans << "\n";
      continue;
    }
    int digits = floor(log10(n)) + 1;
    //   cout<<digits<<endl;
    while (digits--) {
      int digi = (n / div) % 10;
      int x = d ? n % (div) : 0;
    //   cout<<n<<" "<<digi<<" "<<div<<" "<<x<<" "<<div - x<<"\n";
      if (digi == d) {
        n += (div - x);
        ans += (div - x);
      }
      div *= 10;
    }
    cout<<ans<<"\n";
  }
}
