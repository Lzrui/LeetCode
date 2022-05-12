#include<bits/stdc++.h>

using namespace std;
//直接遍历
class Solution {
 public:
  static int minDeletionSize(vector<string>& strs) {
    int row = strs.size();
    int col = strs[0].size();
    int ans = 0;
    for (int j = 0; j < col; ++j) {
      for (int i = 1; i < row; ++i) {
        if (strs[i - 1][j] > strs[i][j]) {
          ans++;
          break;
        }
      }
    }
    return ans;
  }
};


int main()
{
  vector<string> strs = {"zyx","wvu","tsr"};
  cout << Solution::minDeletionSize(strs) << endl;
  return 0;
}