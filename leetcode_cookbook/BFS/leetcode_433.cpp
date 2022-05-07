//
// Created by l50021384 on 2022/5/7.
//
#include <bits/stdc++.h>
using namespace std;
//BFS
class Solution {
 public:
  static int minMutation(string start, string end, vector<string>& bank) {
    unordered_set<string> cnt;
    unordered_set<string> visited;
    char keys[4] = {'A', 'C', 'G', 'T'};
    //哈希化，便于查找
    for (auto & w : bank) {
      cnt.emplace(w);
    }
    if (start == end) {
      return 0;
    }
    if (!cnt.count(end)) {
      return -1;
    }
    queue<string> qu;
    qu.emplace(start);
    visited.emplace(start);
    int step = 1;
    while (!qu.empty()) {
      int sz = qu.size();
      for (int i = 0; i < sz; i++) {
        string curr = qu.front();
        qu.pop();
        for (int j = 0; j < 8; j++) {
          for (int k = 0; k < 4; k++) {
            if (keys[k] != curr[j]) {
              string next = curr;
              next[j] = keys[k];
              if (!visited.count(next) && cnt.count(next)) {
                if (next == end) {
                  return step;
                }
                qu.emplace(next);
                visited.emplace(next);
              }
            }
          }
        }
      }
      step++;
    }
    return -1;
  }
};
//class Solution {
// public:
//  static int minMutation(string start, string end, vector<string>& bank) {
//    int m = start.size();
//    int n = bank.size();
//    //得出可变基因型的合法变换下标
//    vector<vector<int>> adj(n);
//    int endIndex = -1;
//    for (int i = 0; i < n; i++) {
//      if (end == bank[i]) {
//        endIndex = i;
//      }
//      for (int j = i + 1; j < n; j++) {
//        int mutations = 0;
//        for (int k = 0; k < m; k++) {
//          if (bank[i][k] != bank[j][k]) {
//            mutations++;
//          }
//          if (mutations > 1) {
//            break;
//          }
//        }
//        if (mutations == 1) {
//          adj[i].emplace_back(j);
//          adj[j].emplace_back(i);
//        }
//      }
//    }
//    if (endIndex == -1) {
//      return -1;
//    }
//    //找出和start差别为1的所有合法变换入队
//    queue<int> qu;
//    vector<bool> visited(n, false);
//    int step = 1;
//    for (int i = 0; i < n; i++) {
//      int mutations = 0;
//      for (int k = 0; k < m; k++) {
//        if (start[k] != bank[i][k]) {
//          mutations++;
//        }
//        if (mutations > 1) {
//          break;
//        }
//      }
//      if (mutations == 1) {
//        qu.emplace(i);
//        visited[i] = true;
//      }
//    }
//    //BFS
//    while (!qu.empty()) {
//      int sz = qu.size();
//      for (int i = 0; i < sz; i++) {
//        int curr = qu.front();
//        qu.pop();
//        if (curr == endIndex) {
//          return step;
//        }
//        for (auto & next : adj[curr]) {
//          if (visited[next]) {
//            continue;
//          }
//          visited[next] = true;
//          qu.emplace(next);
//        }
//      }
//      step++;
//    }
//    return -1;
//  }
//};

int main(){
  string start("AAAAACCC");
  string end("AACCCCCC");
  vector<string> bank{"AAAACCCC","AAACCCCC","AACCCCCC"};
  cout << Solution::minMutation(start,end,bank) << endl;
  return 0;
}