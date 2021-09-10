// https://practice.geeksforgeeks.org/problems/circular-tour/1

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

int tour(vector<pair<int, int>>& p,int n)
    {
       queue<int> qu;
       int sum = 0;
       int ans = 0;
       bool tr = true;
       for(int i=0; i<n; i++){
           sum += p[i].first - p[i].second;
           if((ans - i == 1 || i - ans == n-1) && sum >= 0) {
               return ans;
           } else if(sum < 0) {
               sum = 0;
               ans = i+1;
           }
           if(i == n-1 && tr) {
               i = -1;
               tr = false;
           }
       }
       return -1;
    }

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin>>n;
    vector<pair<int, int>> p;
    for(int i=0; i<n; i++) {
        int a, b;
        cin>>a>>b;
        pair<int, int> pr = make_pair(a, b);
        p.push_back(pr);
    }
    cout<<tour(p, n)<<endl;
  }
}
