#include<bits/stdc++.h>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root->val > key) {
      root->left = deleteNode(root->left, key);
      return root;
    }
    if (root->val < key) {
      root->right = deleteNode(root->right, key);
      return root;
    }
    if (root->val == key) {
      if (!root->left && !root->right) {
        return nullptr;
      }
      if (!root->right) {
        return root->left;
      }
      if (!root->left) {
        return root->right;
      }
      TreeNode *successor = root->right;
      while (successor->left) {
        successor = successor->left;
      }
      root->right = deleteNode(root->right, successor->val);
      successor->right = root->right;
      successor->left = root->left;
      return successor;
    }
    return root;
  }
};

int main(){
  TreeNode x(2),y(4),z(7);
  TreeNode b(3,&x,&y);
  TreeNode c(6, nullptr,&z);
  TreeNode a(5,&b,&c);
  Solution test;
  TreeNode* res =  test.deleteNode(&a,7);
  return 0;
}