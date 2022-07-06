#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(),n = grid[0].size();
    for(int i=0;i<m;++i){
      for(int j=0;j<n;++j){
        if(!i && !j) continue;
        else if(!i) grid[i][j] = grid[i][j-1] + grid[i][j];
        else if(!j) grid[i][j] = grid[i-1][j] + grid[i][j];
        else grid[i][j] = min(grid[i-1][j],grid[i][j-1])+grid[i][j];
      }
    }
    return grid[m-1][n-1];
  }
};

int main(){
  vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
  cout << Solution::minPathSum(grid) << endl;
  return 0;
}