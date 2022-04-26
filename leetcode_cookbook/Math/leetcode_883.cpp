//
// Created by l50021384 on 2022/4/6.
//
#include <iostream>
#include <vector>
using namespace std;
//数学
class Solution {
 public:
  static int projectionArea(vector<vector<int>> &grid) {
    int n = grid.size();
    int xyArea = 0, yzArea = 0, zxArea = 0;
    for (int i = 0; i < n; i++) {
      int yzHeight = 0, zxHeight = 0;
      for (int j = 0; j < n; j++) {
        xyArea += grid[i][j] > 0 ? 1 : 0;
        yzHeight = max(yzHeight, grid[j][i]);
        zxHeight = max(zxHeight, grid[i][j]);
      }
      yzArea += yzHeight;
      zxArea += zxHeight;
    }
    return xyArea + yzArea + zxArea;
  }
};

int main(){
  vector<vector<int>> grid = {{1,2},{3,4}};
  cout << Solution::projectionArea(grid) << endl;
  return 0;
}



