#include <bits/stdc++.h>

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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty())
      return nullptr;
    int n = preorder.size();
    unordered_map<int, int> InOrder;
    for (int i = 0; i < n; ++i) {
      InOrder[inorder[i]] = i;
    }
    return helper(preorder, InOrder, 0, n - 1, 0);
  }

  TreeNode* helper(vector<int> &preorder, unordered_map<int, int> &InOrder, int left, int right, int pos) {
    if (left > right)
      return nullptr;
    int mid = preorder[pos], index = InOrder[mid], left_len = index - left;
    TreeNode *node = new TreeNode(mid);
    node->left = helper(preorder, InOrder, left, index - 1, pos + 1);
    node->right = helper(preorder, InOrder, index + 1, right, pos + left_len + 1);
    return node;
  }
};

int main() {
  return 0;
}

