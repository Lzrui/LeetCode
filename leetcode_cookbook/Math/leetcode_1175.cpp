#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
 public:
  static int numPrimeArrangements(int n) {
    int numPrimes = 0;
    for (int i = 1; i <= n; i++) {
      if (isPrime(i)) {
        numPrimes++;
      }
    }
    return (int) (factorial(numPrimes) * factorial(n - numPrimes) % MOD);
  }

  static bool isPrime(int n) {
    if (n == 1) {
      return false;
    }
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }

  static long long factorial(int n) {
    long long res = 1;
    for (int i = 1; i <= n; i++) {
      res *= i;
      res %= MOD;
    }
    return res;
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main(){
  int n = 100;
  cout << Solution::numPrimeArrangements(n) << endl;
  return 0;
}