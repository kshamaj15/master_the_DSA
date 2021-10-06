#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin>>t;
  while (t--) {
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int min = arr[0];
    int ans = 0;
    for(int i=n-1 ; i>0; i--) {
        if(arr[i] - min  > 0)
        ans += (arr[i] - min );
    }
    cout<<ans<<endl;
  }
}
