//
// Created by l50021384 on 2022/4/25.
//
#include<bits/stdc++.h>
using namespace std;
class Solution{
 public:
  unordered_map<int,int> l,r;
  ListNode* solve(vector<ListNode*> &a) {
    int i, mi = 1e9;
    ListNode *p;
    for (i = 0; i < a.size(); ++i) {
      p = a[i];
      if (!p) continue;
      min = min(mi, p->val);
      while (p->next) {
        r[p->val] = p->next->val;
        l[p->next->val] = p->val;
        p = p->next;
      }
    }
    ListNode *out = new ListNode(mi);
    p = out;
    if (l[mi] > r[mi]) {
      while (r[p->val] != mi) {
        p->next = new ListNode(r[p->val]);
        p = p->next;
      }
    }
    else {
      while (l[p->val] != mi) {
        p->next = new ListNode(r[p->val]);
        p = p->next;
      }
    }
    return out;
  }
};