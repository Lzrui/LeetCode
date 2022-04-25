//
// Created by l50021384 on 2022/4/6.
//
#include <bits\stdc++.h>
using namespace std;
//水塘抽样
class Solution {
  vector<int> &nums;
 public:
  explicit Solution(vector<int> &nums) : nums(nums) {}

  int pick(int target) {
    int ans;
    for (int i = 0, cnt = 0; i < nums.size(); ++i) {
      if (nums[i] == target) {
        ++cnt; // 第 cnt 次遇到 target
        if (rand() % cnt == 0) {
          ans = i;
        }
      }
    }
    return ans;
  }
};
//哈希表
//class Solution {
//  unordered_map<int, vector<int>> pos;
// public:
//  Solution(vector<int> &nums) {
//    for (int i = 0; i < nums.size(); ++i) {
//      pos[nums[i]].push_back(i);
//    }
//  }
//
//  int pick(int target) {
//    auto &indices = pos[target];
//    return indices[rand() % indices.size()];
//  }
//};
int main(){
  srand(unsigned(time(NULL)));
  vector<int> nums ={1,2,3,4,5,3,3,3};
  Solution test(nums);
  cout << test.pick(3) << endl;
  return 0;
}



