#include<bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
      return u[1] < v[1];
    });
    int pos = points[0][1];
    int ans = 1;
    for (const vector<int>& balloon: points) {
      if (balloon[0] > pos) {
        pos = balloon[1];
        ++ans;
      }
    }
    return ans;
  }
};

int main()
{
  vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
  cout << Solution::findMinArrowShots(points) << endl;
  return 0;
}