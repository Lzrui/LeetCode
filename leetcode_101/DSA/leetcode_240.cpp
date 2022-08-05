#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
      int curr = matrix[i][j];
      if (curr == target) return true;
      else if (curr > target) --j;
      else ++i;
    }
    return false;
  }
};

int main(){
  vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
  int target = 20;
  cout << Solution::searchMatrix(matrix, target) << endl;
  return 0;
}