#include <bits/stdc++.h>

using namespace std;
//枚举
//class Solution {
// public:
//  static int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
//    int res = 0, n = startTime.size();
//    for (int i = 0; i < n; ++i) {
//      if (startTime[i] <= queryTime && endTime[i] >= queryTime)
//        ++res;
//    }
//    return res;
//  }
//};
//差分数组
class Solution {
 public:
  static int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int n = startTime.size();
    int maxEndTime = *max_element(endTime.begin(), endTime.end());
    if (queryTime > maxEndTime) {
      return 0;
    }
    vector<int> cnt(maxEndTime + 2);
    for (int i = 0; i < n; i++) {
      cnt[startTime[i]]++;
      cnt[endTime[i] + 1]--;
    }
    int ans = 0;
    for (int i = 0; i <= queryTime; i++) {
      ans += cnt[i];
    }
    return ans;
  }
};
//二分查找
//class Solution {
// public:
//  static int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
//    sort(startTime.begin(), startTime.end());
//    sort(endTime.begin(), endTime.end());
//    int lessStart = upper_bound(startTime.begin(), startTime.end(), queryTime) - startTime.begin();
//    int lessEnd = lower_bound(endTime.begin(), endTime.end(), queryTime) - endTime.begin();
//    return lessStart - lessEnd;
//  }
//};

int main() {
  vector<int> startTime = {1, 2, 3}, endTime = {3, 2, 7};
  int queryTime = 4;
  int ans = Solution::busyStudent(startTime, endTime, queryTime);
  return 0;
}

