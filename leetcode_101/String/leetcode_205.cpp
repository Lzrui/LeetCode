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
   static bool isIsomorphic(string s, string t) {
    vector<int> s_first_index(256, 0), t_first_index(256, 0);
    for (int i = 0; i < s.length(); ++i) {
      if (s_first_index[s[i]] != t_first_index[t[i]]) {
        return false;
      }
      s_first_index[s[i]] = t_first_index[t[i]] = i + 1;
    }
    return true;
   }
};

int main() {
  string s("paper"), t("title");
  bool res = Solution::isIsomorphic(s, t);
  return 0;
}

