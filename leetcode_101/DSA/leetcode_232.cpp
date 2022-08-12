#include<bits/stdc++.h>

using namespace std;

class MyQueue {
 public:
  MyQueue() {
  }

  void push(int x) {
    left.emplace(x);
  }

  int pop() {
    if (right.empty()) {
      while (!left.empty()) {
        right.emplace(left.top());
        left.pop();
      }
    }
    int res = right.top();
    right.pop();
    return res;
  }

  int peek() {
    if (right.empty()) {
      while (!left.empty()) {
        right.emplace(left.top());
        left.pop();
      }
    }
    return right.top();
  }

  bool empty() {
    return left.empty() && right.empty();
  }

 private:
  stack<int> left;
  stack<int> right;
};

int main(){
  MyQueue *my_queue = new MyQueue();
  my_queue->push(1);
  my_queue->push(2);
  int param_1 = my_queue->peek();
  int param_2 = my_queue->pop();
  bool param_3 = my_queue->empty();
  return 0;
}