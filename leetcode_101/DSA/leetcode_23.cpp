#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Comp {
  bool operator() (ListNode* &a, ListNode* &b) {return a->val > b->val;}
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    priority_queue<ListNode*, vector<ListNode*>, Comp> qu;
    for (auto &head : lists) {
      if (head)
        qu.emplace(head);
    }
    ListNode *dummy = new ListNode(0), *curr = dummy;
    while (!qu.empty()) {
      curr->next = qu.top();
      qu.pop();
      curr = curr->next;
      if (curr->next)
        qu.emplace(curr->next);
    }
    return dummy->next;
  }
};


int main() {
  return 0;
};

