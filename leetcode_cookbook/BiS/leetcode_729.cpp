#include<bits/stdc++.h>

using namespace std;

class MyCalendar {
  set<pair<int, int>> booked;

 public:
  bool book(int start, int end) {
    auto it = booked.lower_bound({end, 0});
    if (it == booked.begin() || (--it)->second <= start) {
      booked.emplace(start, end);
      return true;
    }
    return false;
  }
};

int main(){
  MyCalendar* obj = new MyCalendar();
  bool param_1 = obj->book(10,20);
  bool param_2 = obj->book(15,25);
  bool param_3 = obj->book(20,30);
  return 0;
}