#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    int loop = n / 2;
    int start = 0;
    int offset = 1;
    int val = 1;
    int i, j;
    while (loop--) {
      for (j = start; j < n - offset; ++j) {
        ans[start][j] = val++;
      }
      for (i = start; i < n - offset; ++i) {
        ans[i][j] = val++;
      }
      for (; j > start; --j) {
        ans[i][j] = val++;
      }
      for (; i > start; --i) {
        ans[i][j] = val++;
      }
      ++start;
      ++offset;
    }
    if ((n & 1) == 1) {
      ans[n/2][n/2] = val;
    }
    return ans;
  }
};

int main() {
    string s("dasd");
    vector<vector<int>> ans = Solution::generateMatrix(4);
    return 0;
}

