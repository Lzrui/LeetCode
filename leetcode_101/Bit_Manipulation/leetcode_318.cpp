#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int maxProduct(vector<string>& words) {
    unordered_map<int, int> hash;
    int res = 0;
    for (const auto & word : words) {
      int mask = 0, len = word.size();
      for (auto & ch : word) {
        mask |= 1 << (ch - 'a');
      }
      hash[mask] = max(hash[mask], len);
      for (const auto & [h_mask, h_len] : hash) {
        if (!(h_mask & mask)) {
          res = max(res, len * h_len);
        }
      }
    }
    return res;
  }
};

int main(){
  vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
  cout << Solution::maxProduct(words) << endl;
  return 0;
}