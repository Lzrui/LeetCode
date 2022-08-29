#include <bits/stdc++.h>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     explicit ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//迭代法
//class Solution {
// public:
//  ListNode* reverseList(ListNode* head) {
//    ListNode *prev = nullptr, *next;
//    while (head) {
//      next = head->next;
//      head->next = prev;
//      prev = head;
//      head = next;
//    }
//    return prev;
//  }
//};
//递归法
class Solution {
 public:
  ListNode* reverseList(ListNode* head, ListNode *prev = nullptr) {
    if (!head)
      return prev;
    ListNode *next = head->next;
    head->next = prev;
    return reverseList(next, head);
  }
};

int main() {
  return 0;
}

