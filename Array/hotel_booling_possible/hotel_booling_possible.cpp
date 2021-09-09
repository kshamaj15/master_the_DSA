// https://www.interviewbit.com/problems/hotel-bookings-possible/

#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <utility>
using namespace std;

bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
  int n = arrive.size();
  sort(arrive.begin(), arrive.end());
  sort(depart.begin(), depart.end());

  int i = 0, j = 0;
  int count = 0;

  while (i < n && j < n) {
    if (count > K)
      return false;
    if (arrive[i] >= depart[j]) {
      count--;
      j++;
    } else {
      count++;
      i++;
    }
  }
  if (count > K)
    return false;
  return true;
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
    cin >> n;
    vector<int> arrive(n);
    vector<int> depart(n);
    for (int i = 0; i < n; i++)
      cin >> arrive[i];
    for (int i = 0; i < n; i++)
      cin >> depart[i];

    int k;
    cin >> k;
    cout << hotel(arrive, depart, k)<<endl;
  }
}