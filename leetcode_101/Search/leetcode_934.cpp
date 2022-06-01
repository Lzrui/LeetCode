#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> dirs{-1,0,1,0,-1};

  int shortestBridge(vector<vector<int>>& grid) {
    int m = grid.size(),n = grid[0].size();
    queue<pair<int,int>> qu;
    for(int i=0;i<m;++i){
      for(int j=0;j<n;++j){
        if(grid[i][j] == 1){
          dfs(grid,qu,m,n,i,j);
          goto bfs;
        }
      }
    }
    bfs:int x,y;
    int level = 0;
    while(!qu.empty()){
      ++level;
      int len = qu.size();
      while(len--){
        auto[r,c] = qu.front();
        qu.pop();
        for(int j=0;j<4;++j){
          x = r + dirs[j];
          y = c + dirs[j+1];
          if(x >= 0 && y >= 0 && x < m && y < n){
            if(grid[x][y] == 2)
              continue;
            if(grid[x][y] == 1)
              return level;
            qu.push({x,y});
            grid[x][y] = 2;
          }
        }
      }
    }
    return 0;
  }

  void dfs(vector<vector<int>>& grid,queue<pair<int,int>>& qu,int m,int n,int i,int j){
    if(i < 0 || j < 0 || i == m || j == n || grid[i][j] == 2) return;
    if(grid[i][j] == 0){
      qu.push({i,j});
      return;
    }
    grid[i][j] = 2;
    dfs(grid,qu,m,n,i+1,j);
    dfs(grid,qu,m,n,i,j+1);
    dfs(grid,qu,m,n,i-1,j);
    dfs(grid,qu,m,n,i,j-1);
  }
};

int main(){
  vector<vector<int>> grid = {{0,1,0},{0,0,0},{0,0,1}};
  Solution test;
  cout << test.shortestBridge(grid) << endl;
  return 0;
}