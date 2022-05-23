#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  /*优先进行右下操作，与目的坐标匹配概率较大*/
  int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1},};

  /*转变为BFS求最短路径问题*/
  int bfs(vector<vector<int>> &forest,int c_row,int c_col,int d_row,int d_col){
    if(c_row == d_row && c_col == d_col)
      return 0;
    int m = forest.size(),n = forest[0].size(),step = 0;
    vector<vector<bool>> visited(m,vector<bool>(n, false));
    queue<pair<int,int>> qu;
    qu.emplace(c_row,c_col);
    /*维护队列*/
    while(!qu.empty()){
      ++step;
      int sz = qu.size();
      for(int i=0;i<sz;++i){
        auto [cx,cy] = qu.front();
        qu.pop();
        for(auto &dir:dirs){
          int nx = cx+dir[0];
          int ny = cy+dir[1];
          if(nx >= 0 && nx < m && ny >= 0 && ny < n){
            if(!visited[nx][ny] && forest[nx][ny]){
              if(nx == d_row && ny == d_col)
                return step;
              qu.emplace(nx,ny);
              visited[nx][ny] = true;
            }
          }
        }
      }
    }
    return -1;
  }

  int cutOffTree(vector<vector<int>>& forest) {
    /*记录所有包含数的网格坐标*/
    vector<pair<int,int>> trees;
    int row = forest.size();
    int col = forest[0].size();
    for(int i=0;i<row;++i)
      for(int j=0;j<col;++j){
        if(forest[i][j] > 1)
          trees.emplace_back(i,j);
      }
    /*对网格坐标按照树的高度从小到大排序*/
    sort(trees.begin(),trees.end(),[&](const pair<int,int> &a,const pair<int,int> &b){
      return forest[a.first][a.second] < forest[b.first][b.second];
    });
    int curr_x = 0,curr_y = 0,res = 0;
    for(int i =0;i<trees.size();++i){
      /*计算出从当前位置到待砍伐位置的步长，如果不可到达则返回-1*/
      int steps = bfs(forest,curr_x,curr_y,trees[i].first,trees[i].second);
      if(steps == -1)
        return -1;
      res += steps;
      curr_x = trees[i].first;
      curr_y = trees[i].second;
    }
    return res;
  }
};

int main(){

  vector<vector<int>> foreset = {{1,2,3},{0,0,4},{7,6,5}};
  Solution test;
  cout <<test.cutOffTree(foreset) << endl;
  return 0;
}