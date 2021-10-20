#include <iostream>
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
    string s;
    cin >> s;
    bool ans = false;
    int rc = 0, lc = 0;
    int i = 1;
    if (s[0] == 'L')
      lc = 1;
    else
      rc = 1;
    do {
      if (s[i] == 'L') {
        lc++;
        rc = 0;
      } else if (s[i] == 'R') {
        rc++;
        lc = 0;
      }
      if (rc == 2 || lc == 2) {
        cout << i << " " << lc << " " << rc << endl;
        cout << "YES\n";
        ans = true;
        break;
      }
    } while (s[i++] != '\0');
    if (!ans)
      cout << "NO\n";
  }
  return 0;
}
