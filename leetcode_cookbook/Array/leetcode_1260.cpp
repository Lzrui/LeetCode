#include<bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> ret(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int index1 = (i * n + j + k) % (m * n);
        ret[index1 / n][index1 % n] = grid[i][j];
      }
    }
    return ret;
  }
};

int main(){
  vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
  vector<vector<int>> res = Solution::shiftGrid(grid,2);
  return 0;
}