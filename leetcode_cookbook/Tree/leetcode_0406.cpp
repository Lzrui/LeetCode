#include<bits/stdc++.h>

using namespace std;
//中序遍历
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    stack<TreeNode*> st;
    TreeNode *prev = nullptr, *curr = root;
    while (!st.empty() || curr != nullptr) {
      while (curr != nullptr) {
        st.emplace(curr);
        curr = curr->left;
      }
      curr = st.top();
      st.pop();
      if (prev == p) {
        return curr;
      }
      prev = curr;
      curr = curr->right;
    }
    return nullptr;
  }
};
//利用二叉搜索树的性质
class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode *successor = nullptr;
    if (p->right != nullptr) {
      successor = p->right;
      while (successor->left != nullptr) {
        successor = successor->left;
      }
      return successor;
    }
    TreeNode *node = root;
    while (node != nullptr) {
      if (node->val > p->val) {
        successor = node;
        node = node->left;
      } else {
        node = node->right;
      }
    }
    return successor;
  }
};