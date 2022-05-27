#include<bits/stdc++.h>

using namespace std;
//基于桶
//class Solution {
// public:
//  static vector<int> topKFrequent(vector<int>& nums, int k) {
//    unordered_map<int,int> counts;
//    int max_count = 0;
//    for(auto &num:nums){
//      max_count = max(max_count,++counts[num]);
//    }
//    vector<vector<int>> buckets(max_count+1);
//    for(auto &val:counts){
//      buckets[val.second].emplace_back(val.first);
//    }
//    vector<int> res;
//    for(int i = max_count;i>=0 && res.size()<k;--i){
//      for(auto &num: buckets[i]){
//        res.emplace_back(num);
//        if(res.size() == k)
//          break;
//      }
//    }
//    return res;
//  }
//};
//基于小根堆
class Solution {
 public:
  static bool cmp(pair<int, int>& m, pair<int, int>& n) {
    return m.second > n.second;
  }

  static vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> occurrences;
    for (auto& v : nums) {
      occurrences[v]++;
    }

    // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)*> q(cmp);
    for (auto& [num, count] : occurrences) {
      if (q.size() == k) {
        if (q.top().second < count) {
          q.pop();
          q.emplace(num, count);
        }
      } else {
        q.emplace(num, count);
      }
    }
    vector<int> ret;
    while (!q.empty()) {
      ret.emplace_back(q.top().first);
      q.pop();
    }
    return ret;
  }
};

int main(){
  vector<int> nums = {1,1,1,2,2,3};
  int k = 2;
  vector<int> res = Solution::topKFrequent(nums,k);
  return 0;
}