#include <bits/stdc++.h>

using namespace std;

class NumMatrix {
 public:
  NumMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    sums = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j) {
        sums[i][j] = matrix[i-1][j-1] + sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
      }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
  }
 private:
  vector<vector<int>> sums;
};

int main() {
  vector<vector<int>> matrix = {{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
  NumMatrix test(matrix);
  int ans = test.sumRegion(2, 1, 4, 3);
  return 0;
}

