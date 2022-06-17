#include<bits/stdc++.h>

using namespace std;
//双指针
class Solution {
 public:
  static void duplicateZeros(vector<int>& arr) {
    int n = arr.size();
    int top = 0;
    int i = -1;
    //双指针查找待放入在最后位置的元素下标
    while (top < n) {
      i++;
      if (arr[i] != 0) {
        top++;
      } else {
        top += 2;
      }
    }
    int j = n - 1;
    //放置在最后位置的元素为0，溢出，故仅放一个0之后前移即可
    if (top == n + 1) {
      arr[j] = 0;
      j--;
      i--;
    }
    //放置过程
    while (j >= 0) {
      arr[j] = arr[i];
      j--;
      if (!arr[i]) {
        arr[j] = arr[i];
        j--;
      }
      i--;
    }
  }
};

int main(){
  vector<int> nums = {1,0,2,3,0,4,5,0};
  Solution::duplicateZeros(nums);
  return 0;
}