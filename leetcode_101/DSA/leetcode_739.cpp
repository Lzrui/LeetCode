#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n);
    stack<int> indices;
    for (int i = 0; i < n; ++i) {
      while (!indices.empty()) {
        int idx =indices.top();
        if (temperatures[i] <= temperatures[idx])
          break;
        indices.pop();
        ans[idx] = i - idx;
      }
      indices.push(i);
    }
    return ans;
  }
};

int main() {
  vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
  vector<int> res = Solution::dailyTemperatures(temperatures);
  return 0;
};

