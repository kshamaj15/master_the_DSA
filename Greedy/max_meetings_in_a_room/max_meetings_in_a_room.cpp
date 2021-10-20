// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

#include <bits/stdc++.h>
#include <string>

using namespace std;

bool mycompare(pair<int, int> p1, pair<int, int> p2) {
  return p1.second < p2.second;
}

int maxMeetings(int start[], int end[], int n) {
  vector<pair<int, int>> meetings;
  for (int i = 0; i < n; i++) {
    pair<int, int> p = make_pair(start[i], end[i]);
    meetings.push_back(p);
  }
  sort(meetings.begin(), meetings.end(), mycompare);
  int count = 0;
  int prev = 0;
  for (int i = 0; i < n; i++) {
    if (meetings[i].first > prev) {
      count++;
      prev = meetings[i].second;
    }
  }
  return count;
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
    int start[n];
    int end[n];
    for (int i = 0; i < n; i++) {
      cin >> start[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> end[i];
    }
    cout << maxMeetings(start, end, n) << endl;
  }
}
