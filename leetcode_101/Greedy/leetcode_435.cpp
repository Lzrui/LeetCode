#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    if (intervals.empty()) {
      return 0;
    }
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
      return a[1] < b[1];
    });
    int total = 0, prev = intervals[0][1];
    for (int i = 1; i < n; ++i) {
      if (intervals[i][0] < prev) {
        ++total;
      } else {
        prev = intervals[i][1];
      }
    }
    return total;
  }
};

int main()
{
  vector<vector<int>> test = {{1,3},{3,6},{5,6},{6,7}};
  cout << Solution::eraseOverlapIntervals(test) << endl;
  return 0;
}