#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    unordered_map<int, int> ranks;
    vector<int> ans(arr.size());
    for (auto &a : sortedArr) {
      if (!ranks.count(a)) {
        ranks[a] = ranks.size() + 1;
      }
    }
    for (int i = 0; i < arr.size(); i++) {
      ans[i] = ranks[arr[i]];
    }
    return ans;
  }
};



int main(){
  vector<int> arr = {37,12,28,9,100,56,80,5,12};
  vector<int> res = Solution::arrayRankTransform(arr);
  return 0;
}