#include<bits/stdc++.h>

using namespace std;

//回溯法
//class Solution {
// public:
//  bool dfs(int index, vector<int> &matchsticks, vector<int> &edges, int len) {
//    if (index == matchsticks.size()) {
//      return true;
//    }
//    for (int i = 0; i < edges.size(); i++) {
//      // 修改当前节点状态
//      edges[i] += matchsticks[index];
//      // 递归子节点
//      if (edges[i] <= len && dfs(index + 1, matchsticks, edges, len)) {
//        return true;
//      }
//      // 回改当前节点状态
//      edges[i] -= matchsticks[index];
//    }
//    return false;
//  }
//
//  bool makesquare(vector<int> &matchsticks) {
//    int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
//    if (totalLen % 4 != 0) {
//      return false;
//    }
//    sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // 减少搜索量
//
//    vector<int> edges(4);
//    return dfs(0, matchsticks, edges, totalLen / 4);
//  }
//};
//状态压缩 + 动态规划
class Solution {
 public:
  bool makesquare(vector<int>& matchsticks) {
    int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (totalLen % 4 != 0) {
      return false;
    }
    int len = totalLen / 4, n = matchsticks.size();
    //dp[s]表示正方形未放满的边的当前长度
    vector<int> dp(1 << n, -1);
    dp[0] = 0;
    //状态s记录哪些火柴已经被放入
    for (int s = 1; s < (1 << n); s++) {
      for (int k = 0; k < n; k++) {
        //如果当前火柴未放入，则校验下一个火柴
        if ((s & (1 << k)) == 0) {
          continue;
        }
        //s1为去掉它的第k根火柴得到的状态
        int s1 = s & ~(1 << k);
        if (dp[s1] >= 0 && dp[s1] + matchsticks[k] <= len) {
          //因为放满前一条边后，我们开始放后一条边，此时未放满的边的长度为0，所以需要对len取余
          dp[s] = (dp[s1] + matchsticks[k]) % len;
          break;
        }
      }
    }
    return dp[(1 << n) - 1] == 0;
  }
};

int main(){
  vector<int> matchsticks = {5,5,5,5,4,4,4,4,3,3,3,3};
  Solution test;
  cout << test.makesquare(matchsticks) << endl;
  return 0;
}