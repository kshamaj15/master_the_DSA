#include <cstring>
#include <iostream>
#include <vector>
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
    int mod = 1000000007;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long int ans = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      int m = 0;
      int sum = 0;
      for (int j = i; j < n; j++) {
        m = max(m, arr[j]);
        sum += m % mod;
        ans += sum % mod;
      }
    }
    cout << ans%mod << "\n";
  }
  return 0;
}