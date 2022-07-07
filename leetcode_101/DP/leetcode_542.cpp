#include<bits/stdc++.h>
#include<sstream>
using namespace std;
//BFS
//class Solution {
// public:
//  vector<int> dirs = {-1,0,1,0,-1};
//    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//    int m = mat.size(),n =mat[0].size();
//    vector<vector<int>> res(m,vector<int>(n));
//    queue<pair<int,int>> qu;
//    for(int i=0;i<m;++i)
//      for(int j=0;j<n;++j){
//        if(mat[i][j]==0){
//          qu.emplace(make_pair(i,j));
//          }
//        }
//    int distance = 0;
//    while(!qu.empty()) {
//      int len = qu.size();
//      for (int i = 0; i < len; ++i) {
//        pair<int, int> curr = qu.front();
//        qu.pop();
//        res[curr.first][curr.second] = distance;
//        for(int k=0;k<4;++k){
//          int u = curr.first+dirs[k],v = curr.second+dirs[k+1];
//          if(u >= 0 && u < m && v >= 0 && v < n && mat[u][v] == 1){
//            qu.emplace(make_pair(u,v));
//            mat[u][v] = 2;
//          }
//        }
//      }
//      ++distance;
//    }
//      return res;
//  }
//};
//DP+Greedy
class Solution {
 public:
  vector<int> dirs = {-1,0,1,0,-1};
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(),n =mat[0].size();
    vector<vector<int>> res(m,vector<int>(n));
    queue<pair<int,int>> qu;
    for(int i=0;i<m;++i)
      for(int j=0;j<n;++j){
        res[i][j] = mat[i][j] == 0?0:10000;
      }
    for(int i=0;i<m;++i)
      for(int j=0;j<n;++j){
        if(!i && !j) continue;
        else if(!i) res[i][j] = min(res[i][j-1]+1,res[i][j]);
        else if(!j) res[i][j] = min(res[i-1][j]+1,res[i][j]);
        else res[i][j] = min(min(res[i][j-1],res[i-1][j])+1,res[i][j]);
      }
    for(int i=m-1;i>=0;--i)
      for(int j=n-1;j>=0;--j){
        if(i==m-1 && j==n-1) continue;
        else if(i==m-1) res[i][j] = min(res[i][j+1]+1,res[i][j]);
        else if(j==n-1) res[i][j] = min(res[i+1][j]+1,res[i][j]);
        else res[i][j] = min(min(res[i][j+1],res[i+1][j])+1,res[i][j]);
      }
    return res;
  }
};

int main(){
  vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
  Solution test;
  vector<vector<int>> res = test.updateMatrix(mat);
  return 0;
}