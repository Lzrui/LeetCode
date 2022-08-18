#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int maxPoints(vector<vector<int>>& points) {
    unordered_map<double, int> lines;
    int n = points.size(), same = 1, same_x = 1, max_count = 0;
    for (int i = 0; i < n; ++i) {
      same = 1, same_x = 1;
      for (int j = i + 1; j < n; ++j) {
       if (points[i][0] == points[j][0]) {
         ++same_x;
         if (points[i][1] == points[j][1]) {
           ++same;
         }
       }
       else {
         double dx = points[i][0] - points[j][0], dy = points[i][1] - points[j][1];
         ++lines[dy/dx];
       }
      }
      max_count = max(max_count, same_x);
      for (auto & [k, nums] : lines) {
        max_count = max(max_count, same + nums);
      }
      lines.clear();
    }
    return max_count;
  }
};

int main() {
  vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
  printf("%d\n", Solution::maxPoints(points));
  return 0;
}

