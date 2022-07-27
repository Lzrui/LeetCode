#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (const string & str: strs) {
      auto [cnt_0, cnt_1] = count(str);
      for (int i = m; i >= cnt_0; --i) {
        for (int j = n; j >= cnt_1; --j) {
          dp[i][j] = max(dp[i][j], dp[i-cnt_0][j-cnt_1] + 1);
        }
      }
    }
    return dp[m][n];
  }

  static pair<int,int> count(const string & s){
    int cnt_0 = s.size(), cnt_1 = 0;
    for (auto & ch: s) {
      if (ch == '1') {
        ++cnt_1;
        --cnt_0;
      }
    }
    return make_pair(cnt_0, cnt_1);
  }
};

int main(){
  vector<string> strs = {"10", "0001", "111001", "1", "0"};
  int m = 5, n = 3;
  cout << Solution::findMaxForm(strs, m, n) << endl;
  return 0;
}