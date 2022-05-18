#include<bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
 public:
  static ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
// 判断是否存在环路
    do {
      if (!fast || !fast->next) return nullptr;
      fast = fast->next->next;
      slow = slow->next;
    } while (fast != slow);
// 如果存在，查找环路节点
    fast = head;
    while (fast != slow) {
      slow = slow->next;
      fast = fast->next;
    }
    return fast;
  }
};

int main(){
  ListNode a(3);
  ListNode b(2);
  ListNode c(0);
  ListNode d(-4);
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &b;
  ListNode *res = Solution::detectCycle(&a);
  return 0;
}