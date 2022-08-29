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
//  static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//    ListNode *dummy = new ListNode(0), *prev = dummy;
//    while (list1 && list2) {
//      if (list1->val <= list2->val) {
//        prev->next = list1;
//        list1 = list1->next;
//      }
//      else {
//        prev->next = list2;
//        list2 = list2->next;
//      }
//      prev = prev->next;
//    }
//    prev->next = list1? list1 : list2;
//    return dummy->next;
//  }
//};

//递归法
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list2)
      return list1;
    if (!list1)
      return list2;
    if (list1->val <= list2->val) {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    }
    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
  }
};

int main() {
  return 0;
}

