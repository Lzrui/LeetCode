#include<bits/stdc++.h>

using namespace std;

class Solution {
  vector<int> origin;
 public:
  explicit Solution(vector<int>& nums):origin(std::move(nums)) {}

  vector<int> reset() {
    return origin;
  }

  vector<int> shuffle() {
    if (origin.empty()) return {};
    vector<int> shuffled(origin);
    int n = origin.size();
    //反向洗牌
    for (int i = n - 1; i >= 0; --i) {
      swap(shuffled[i], shuffled[rand() % (i + 1)]);
    }
    //正向洗牌
//   for (int i = 0; i < n; ++i) {
//   int pos = rand() % (n - i);
//   swap(shuffled[i], shuffled[i+pos]);
//   }
    return shuffled;
  }
};

int main(){
  vector<int> nums = {1, 2, 3};
  auto* obj = new Solution(nums);
  vector<int> param_1 = obj->reset();
  vector<int> param_2 = obj->shuffle();
  return 0;
}