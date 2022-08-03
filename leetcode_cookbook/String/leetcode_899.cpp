#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static string orderlyQueue(string s, int k) {
    if (k == 1) {
      string min_str = s;
      int n = s.size();
      for (int i = 1; i < n; ++i) {
        char ch = s[0];
        s = s.substr(1) + ch;
        min_str = min_str < s ?  min_str : s;
      }
      return min_str;
    }
    sort(s.begin(), s.end());
    return s;
  }
};

int main(){
  string s("cba");
  int k = 1;
  string res = Solution::orderlyQueue(s, k);
  return 0;
}