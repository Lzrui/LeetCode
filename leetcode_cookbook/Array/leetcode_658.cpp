#include <bits/stdc++.h>

using namespace std;

//排序
//class Solution {
// public:
//  static vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//    sort(arr.begin(), arr.end(), [&](const int a, const int b){return abs(a - x) < abs(b - x)
//          || abs(a - x) == abs(b - x) && a < b;});
//    sort(arr.begin(),arr.begin() + k);
//    return {arr.begin(), arr.begin() + k};
//  }
//};

//二分
class Solution {
 public:
  static vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int left = right - 1;
    while (k--) {
      if (left < 0)
        ++right;
      else if (right == arr.size())
        --left;
      else if (abs(arr[left] - x) <=  abs(arr[right] - x))
        --left;
      else
        ++right;
    }
    return {arr.begin() + left + 1, arr.begin() +right};
  }
};

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  int k = 4, x = 3;
  vector<int> res = Solution::findClosestElements(arr, k, x);
  return 0;
}

