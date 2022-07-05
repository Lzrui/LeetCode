#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if(n == 1) return {0};
    vector<int> degree(n);
    vector<vector<int>> adj(n);
    for(auto & edge:edges){
      adj[edge[0]].emplace_back(edge[1]);
      adj[edge[1]].emplace_back(edge[0]);
      ++degree[edge[0]];
      ++degree[edge[1]];
    }
    queue<int> qu;
    vector<int> res;
    for(int i=0;i<n;++i){
      if(degree[i] == 1)
        qu.emplace(i);
    }
    int remain = n;
    while(remain > 2){
      int len = qu.size();
      remain -= len;
      for(int i=0;i<len;++i){
        int curr = qu.front();
        qu.pop();
        for(auto &node:adj[curr]){
          if(--degree[node] == 1)
            qu.emplace(node);
        }
      }
    }
    while(!qu.empty()){
      res.emplace_back(qu.front());
      qu.pop();
    }
    return res;
  }
};

int main(){
  int n=6;
  vector<vector<int>> edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
  Solution test;
  vector<int> res = test.findMinHeightTrees(n,edges);
  return 0;
}