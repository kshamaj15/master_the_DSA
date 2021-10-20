#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10000;
int prefix[MAX + 1];

// prefix[i] is going to store count of primes
// till i (including i).

void buildPrefix() {
  // Create a boolean array "prime[0..n]". A
  // value in prime[i] will finally be false
  // if i is Not a prime, else true.
  vector<bool> prime(MAX+1, true);

  for (int p = 2; p * p <= MAX; p++) {

    // If prime[p] is not changed, then
    // it is a prime
    if (prime[p] == true) {

      // Update all multiples of p
      for (int i = p * 2; i <= MAX; i += p)
        prime[i] = false;
    }
  }

  // Build prefix array
  prefix[0] = prefix[1] = 0;
  for (int p = 2; p <= MAX; p++) {
    prefix[p] = prefix[p - 1];
    if (prime[p])
      prefix[p]++;
  }
}

int query(int L, int R) { return prefix[R] - prefix[L - 1]; }

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
buildPrefix();
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    cout << y - x - query(x+2, y) << "\n";
  }
  return 0;
}



// bool isPrime(int num){
//     for(int i=2; i*i <= num; i++){
//         if(num%i == 0) return false;
//     }
//     return true;
// }

// int countPrime(int x, int y){
//     int count = 0;
//     for(int i=x+2; i<=y; i++){
//         if(isPrime(i)) count++;
//     }
//     return count;
// }