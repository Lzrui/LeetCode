#include <bits/stdc++.h>

using namespace std;

//暴力法
//class Solution {
// public:
//  static int strStr(string haystack, string needle) {
//    int m = haystack.size(), n = needle.size();
//    for (int i = 0; i + n <= m; ++i) {
//      bool flag = true;
//      for (int j = 0; j < n; ++j) {
//        if (haystack[i + j] != needle[j]) {
//          flag = false;
//          break;
//        }
//      }
//      if (flag)
//        return i;
//    }
//    return -1;
//  }
//};

// KMP算法
class Solution {
 public:
  static int strStr(string haystack, string needle) {
    int m = haystack.size(), n = needle.size();
    if (n == 0) return 0;
    vector<int> next(n, -1);
    calNext(needle, next);
    for (int i = 0, k = -1; i < m; ++i) {
      while (k > -1  && needle[k+1] != haystack[i]) {
        k = next[k];
      }
      if (needle[k+1] == haystack[i]) {
        ++k;
      }
      if (k == n - 1) {
        return i - n + 1;
      }
    }
    return -1;
  }

  static void calNext(const string &needle, vector<int> &next) {
    for (int j = 1, p = -1; j <  needle.size(); ++j) {
      while (p > -1 && needle[p+1] != needle[j]) {
        p = next[p];
      }
      if (needle[p+1] == needle[j]) {
        ++p;
      }
      next[j] = p;
    }
  }

};

int main() {
  string haystack("ababadababababc"), needle("ababc");
  int res = Solution::strStr(haystack, needle);
  return 0;
}

