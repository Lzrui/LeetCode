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

//普通DFS
//class Solution {
// public:
//  bool isUnivalTree(TreeNode* root) {
//    if (!root) {
//      return true;
//    }
//    if (root->left) {
//      if (root->val != root->left->val || !isUnivalTree(root->left)) {
//        return false;
//      }
//    }
//    if (root->right) {
//      if (root->val != root->right->val || !isUnivalTree(root->right)) {
//        return false;
//      }
//    }
//    return true;
//  }
//};
//整活DFS
class Solution {
 public:
  bool isUnivalTree(TreeNode* root) {
    return (!root->left || ((root->val == root->left->val) && isUnivalTree(root->left))) &&
        (!root->right || ((root->val == root->right->val) && isUnivalTree(root->right)));
  }
};