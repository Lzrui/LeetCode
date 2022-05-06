//
// Created by l50021384 on 2022/4/6.
//
#include <bits/stdc++.h>
using namespace std;
//队列
class RecentCounter {
  queue<int> q;
 public:RecentCounter() = default;

  int ping(int t) {
    q.push(t);
    while (q.front() < t - 3000) {
      q.pop();
    }
    return q.size();
  }
};

int main(){
  auto* obj = new RecentCounter();
  cout << obj->ping(3) << endl;
  return 0;
}



