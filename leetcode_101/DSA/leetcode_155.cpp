#include<bits/stdc++.h>

using namespace std;

class MinStack {
 public:
  MinStack() {

  }

  void push(int val) {
    if (right.empty() || val <= right.top()) {
      right.emplace(val);
    }
    left.emplace(val);
  }

  void pop() {
    int val = left.top();
    left.pop();
    if (right.top() == val)
      right.pop();
  }

  int top() {
    return left.top();
  }

  int getMin() {
    return right.top();
  }

 private:
  stack<int> left;
  stack<int> right;
};

int main() {
  auto *min_stack = new MinStack();
  return 0;
}