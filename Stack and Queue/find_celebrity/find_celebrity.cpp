#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool isCeleb(vector<vector<int>> &arr, int id) {
  for (int i = 0; i < arr.size(); i++) {
    if (i != id && (arr[id][i] || arr[i][id] == 0))
      return false;
  }
  return true;
}

int celebrity(vector<vector<int>> &arr, int n) {
  int a = 0;
  int b = n - 1;
  unordered_set<int> st;
  while (a < b) {
    if (arr[a][b] == 0 && arr[b][a]) {
      st.insert(a);
      if(st.find(b) != st.end())
      st.erase(b);
      a++;
    } else if (arr[b][a] == 0 && arr[a][b]) {
      st.insert(b);
      if(st.find(a) != st.end())
      st.erase(a);
      b--;
    } else {
      a++;
    }
  }
  for (auto it = st.begin(); it != st.end(); it++) {
    if(isCeleb(arr ,*it)) return *it;
  }
  return -1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin>>arr[i][j];
            }
        }
        cout<<celebrity(arr, n)<<endl;
    }
}
