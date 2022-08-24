#include <bits/stdc++.h>

using namespace std;

//class Solution {
// public:
//  static bool isIsomorphic(string s, string t) {
//    unordered_map<char, char> hash_st;
//    unordered_map<char, char> hash_ts;
//    int n = s.size();
//    for (int i = 0; i < n; ++i) {
//      if ((hash_st.count(s[i]) && hash_st[s[i]] != t[i]) ||
//          (hash_ts.count(t[i]) && hash_ts[t[i]] != s[i]))
//        return false;
//      hash_st[s[i]] = t[i];
//      hash_ts[t[i]] = s[i];
//    }
//    return true;
//  }
//};

class Solution {
 public:
  static int countSubstrings(string s) {
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
      count += extendSubstrings(s, i, i);
      count += extendSubstrings(s, i, i + 1);
    }
    return count;
  }

  static int extendSubstrings(string &s, int l, int r) {
    int count = 0;
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      --l;
      ++r;
      ++count;
    }
    return count;
  }
};

int main() {
  string s("aaa");
  int res = Solution::countSubstrings(s);
  return 0;
}

