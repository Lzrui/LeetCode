//
// Created by l50021384 on 2022/4/6.
//
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
 public:
  static vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) {
      return {0};
    }
    vector<int> degree(n);
    vector<vector<int>> adj(n);
    for (auto & edge : edges){
      adj[edge[0]].emplace_back(edge[1]);
      adj[edge[1]].emplace_back(edge[0]);
      degree[edge[0]]++;
      degree[edge[1]]++;
    }
    queue<int> qu;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (degree[i] == 1) {
        qu.emplace(i);
      }
    }
    int remainNodes = n;
    while (remainNodes > 2) {
      int sz = qu.size();
      remainNodes -= sz;
      for (int i = 0; i < sz; i++) {
        int curr = qu.front();
        qu.pop();
        for (auto & v : adj[curr]) {
          if (--degree[v] == 1) {
            qu.emplace(v);
          }
        }
      }
    }
    while (!qu.empty()) {
      ans.emplace_back(qu.front());
      qu.pop();
    }
    return ans;
  }
};

int main(){
  int n = 6;
  vector<vector<int>> edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
  vector<int> res = Solution::findMinHeightTrees(n,edges);
  return 0;
}



