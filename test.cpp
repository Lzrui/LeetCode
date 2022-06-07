#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
// 主函数
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    backtracking(nums, 0, ans);
    return ans;
  }
// 辅函数
  void backtracking(vector<int> &nums, int level, vector<vector<int>> &ans) {
    if (level == nums.size() - 1) {
      ans.push_back(nums);
      return; }
    for (int i = level; i < nums.size(); i++) {
      swap(nums[i], nums[level]); // 修改当前节点状态
      backtracking(nums, level+1, ans); // 递归子节点
      swap(nums[i], nums[level]); // 回改当前节点状态
    } }
};

int main(){
  vector<int> nums = {1,2,3};
  Solution test;
  vector<vector<int>> res = test.permute(nums);
  return 0;
}