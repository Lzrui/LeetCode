#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    unordered_map<int, vector<int>> group;
    int n = groupSizes.size();
    for (int i = 0; i < n; ++i) {
      group[groupSizes[i]].emplace_back(i);
    }
    vector<vector<int>> res;
    for (auto iter = group.begin(); iter != group.end(); ++iter) {
      int times = iter->second.size() / iter->first;
      int first = 0;
      for (int i = 0; i < times; ++i) {
        vector<int> temp;
        for (int j = first; j < first + iter->first; ++j) {
          temp.emplace_back(iter->second[j]);
        }
        first += iter->first;
        res.emplace_back(std::move(temp));
      }
    }
    return res;
  }
};

int main(){
  vector<int> groupSizes = {3,3,3,3,3,1,3};
  vector<vector<int>> res = Solution::groupThePeople(groupSizes);
  return 0;
}