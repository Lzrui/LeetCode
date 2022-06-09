#include<bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static int heightChecker(vector<int>& heights) {
    int m = *max_element(heights.begin(), heights.end());
    vector<int> cnt(m + 1);
    for (int h: heights) {
      ++cnt[h];
    }

    int idx = 0, ans = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= cnt[i]; ++j) {
        if (heights[idx] != i) {
          ++ans;
        }
        ++idx;
      }
    }
    return ans;
  }
};

int main(){
  vector<int> heights = {1,1,4,2,1,3};
  cout << Solution::heightChecker(heights) << endl;
  return 0;
}