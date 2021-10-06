#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  vector<int> ans(n);
  int index = n / 2;
  bool isLeft = true;
  if (n % 2 == 1) {
    isLeft = false;
  } 
  for (int i = 1; i <= n; i++) {
    int temp;
    cin >> temp;
    ans[index] = temp;
    if (isLeft)
      index -= i;
    else
      index += i;
    isLeft = !isLeft;
  }

  for (auto el : ans)
    cout << el << " ";

  return 0;
}
