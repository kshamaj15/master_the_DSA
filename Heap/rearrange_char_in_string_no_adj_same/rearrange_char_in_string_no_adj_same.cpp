#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAX_CHAR = 26;

// struct Key {
//     int freq;
//     char ch;
//     // operator overloading
//     bool operator<(const Key k){
//         return  freq < k.freq;
//     }
// };

int f(int a, int b) {
  if (a < b) {
    return f(b, a);
  } else if (b != 0) {
    return a * f(a, b - 1);
  } else {
    return 0;
  }
}

int main() {
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  // #endif

  int a = 5, b = 2;
  cout << f(5, 5) << endl;

  // int t;
  // cin >> t;
  // while (t--) {
  //   string str;
  //   cin >> str;
  //   int n = str.size();
  //   int count[MAX_CHAR] = {0};

  //   for (int i = 0; i < n; i++)
  //     count[str[i] - 'a']++;

  //   string ans = "";
  //   priority_queue<Key> pq;

  //   for (char c = 'a'; c <= 'z'; c++)
  //       if (count[c])
  //           pq.push(Key{ count[c], c });

  //   Key prev = {-1, '#'};
  //   while (!pq.empty()) {
  //       ans += pq.top().ch;

  //   }

  // }
}
