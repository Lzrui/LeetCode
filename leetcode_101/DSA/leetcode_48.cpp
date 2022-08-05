#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static void rotate(vector<vector<int>>& matrix) {
    int temp = 0, n = matrix.size() - 1;
    for (int i = 0; i <= n / 2; ++i) {
      for (int j = i; j < n - i; ++j) {
        temp = matrix[i][j];
        matrix[i][j] = matrix[n-j][i];
        matrix[n-j][i] = matrix[n-i][n-j];
        matrix[n-i][n-j] = matrix[j][n-i];
        matrix[j][n-i] = temp;
      }
    }
  }
};

int main(){
  vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
  Solution::rotate(matrix);
  return 0;
}