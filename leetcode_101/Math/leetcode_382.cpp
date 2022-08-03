#include<bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  ListNode *head;
 public:
  Solution(ListNode* head) : head(head) {}

  int getRandom() {
    int ans = head->val;
    int i = 2;
    ListNode *node = head->next;
    while (node) {
      if (rand() % i++ == 0)
        ans = node->val;
      node = node->next;
    }
    return ans;
  }
};

int main(){
  vector<int> w = {1, 2, 3, 4, 5};
  ListNode *head = new ListNode(w[0]);
  ListNode *temp = head;
  for (int i = 1; i < w.size(); ++i) {
    temp->next = new ListNode(w[i]);
    temp = temp->next;
  }
  Solution *obj = new Solution(head);
  for (int i = 0; i < 10; ++i) {
    cout << obj->getRandom() << endl;
  }
  return 0;
}