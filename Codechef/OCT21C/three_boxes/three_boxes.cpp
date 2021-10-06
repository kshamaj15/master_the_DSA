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
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int count = 1;
    int bagCap = d-a;
    if(bagCap >= b) {
        bagCap -= b;
    } else {
        bagCap = d-b;
        count++;
    }
    if(bagCap >= c) {
        bagCap -= c;
    } else {
        count++;
    }
    cout<<count<<"\n";
  }
}
