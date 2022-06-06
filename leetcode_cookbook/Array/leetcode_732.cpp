#include<bits/stdc++.h>

using namespace std;

class MyCalendarThree {
 public:
  unordered_map<int, pair<int, int>> tree;

  MyCalendarThree() {

  }

  void update(int start, int end, int l, int r, int idx) {
    if (r < start || end < l) {
      return;
    }
    if (start <= l && r <= end) {
      tree[idx].first++;
      tree[idx].second++;
    } else {
      int mid = (l + r) >> 1;
      update(start, end, l, mid, 2 * idx);
      update(start, end, mid + 1, r, 2 * idx + 1);
      tree[idx].first = tree[idx].second + max(tree[2 * idx].first, tree[2 * idx + 1].first);
    }
  }

  int book(int start, int end) {
    update(start, end - 1, 0, 1e9, 1);
    return tree[1].first;
  }
};

int main(){
  MyCalendarThree myCalendarThree;
  int res = myCalendarThree.book(10, 20); // 返回 1 ，第一个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
  res =  myCalendarThree.book(50, 60); // 返回 1 ，第二个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
  res = myCalendarThree.book(10, 40); // 返回 2 ，第三个日程安排 [10, 40) 与第一个日程安排相交，所以最大 k 次预订是 2 次预订。
  res = myCalendarThree.book(5, 15); // 返回 3 ，剩下的日程安排的最大 k 次预订是 3 次预订。
  res = myCalendarThree.book(5, 10); // 返回 3
  res = myCalendarThree.book(25, 55); // 返回 3

  return 0;
}