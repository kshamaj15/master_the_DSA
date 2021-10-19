// https://www.codechef.com/SNCKQL21/problems/MINDIFF1
#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

bool mycomapre(vector<int> a, vector<int> b){
    return a.size() > b.size();
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v);
    vector<int> ans(v);
    for (int i = 0; i < v; i++) {
        adj[i].push_back(i);
    }
    for (int i = 0; i < e; i++) {
      int x, y;
      cin >> x >> y;
      adj[x-1].push_back(y-1);
      adj[y-1].push_back(x-1);
    }
    sort(adj.begin(), adj.end(), mycomapre);
    int mx = 0;
    for (int i=0; i<v; i++) {
        ans[adj[i][0]] = i+1;
        int count = 0;
        for (int j=1; j<adj[i].size(); j++) {
            if(adj[i][j] < i)
            count++;
        }
        mx = max(count, mx);
    }
    cout<<mx<<"\n";
    for (int i=0; i<v; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
  }
}
