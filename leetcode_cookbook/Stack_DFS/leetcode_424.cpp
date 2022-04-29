//
// Created by l50021384 on 2022/4/6.
//
#include<vector>
#include <iostream>
using namespace std;
class Node {
 public:
  bool val;
  bool isLeaf;
  Node* topLeft;
  Node* topRight;
  Node* bottomLeft;
  Node* bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = nullptr;
    topRight = nullptr;
    bottomLeft = nullptr;
    bottomRight = nullptr;
  }

  Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};
#include <functional>
//递归
//class Solution {
// public:
//  static Node *construct(vector<vector<int>> &grid) {
//    function<Node*(int, int, int, int)> dfs = [&](int r0, int c0, int r1, int c1) {
//      for (int i = r0; i < r1; ++i) {
//        for (int j = c0; j < c1; ++j) {
//          if (grid[i][j] != grid[r0][c0]) { // 不是叶节点
//            return new Node(
//                true,
//                false,
//                dfs(r0, c0, (r0 + r1) / 2, (c0 + c1) / 2),
//                dfs(r0, (c0 + c1) / 2, (r0 + r1) / 2, c1),
//                dfs((r0 + r1) / 2, c0, r1, (c0 + c1) / 2),
//                dfs((r0 + r1) / 2, (c0 + c1) / 2, r1, c1)
//            );
//          }
//        }
//      }
//      // 是叶节点
//      return new Node(grid[r0][c0], true);
//    };
//    return dfs(0, 0, grid.size(), grid.size());
//  }
//};
//递归加二维前缀和优化
class Solution {
 public:
  static Node *construct(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<vector<int>> pre(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + grid[i - 1][j - 1];
      }
    }

    auto getSum = [&](int r0, int c0, int r1, int c1) {
      return pre[r1][c1] - pre[r1][c0] - pre[r0][c1] + pre[r0][c0];
    };

    function<Node *(int, int, int, int)> dfs = [&](int r0, int c0, int r1, int c1) {
      int total = getSum(r0, c0, r1, c1);
      if (total == 0) {
        return new Node(false, true);
      }
      if (total == (r1 - r0) * (c1 - c0)) {
        return new Node(true, true);
      }
      return new Node(
          true,
          false,
          dfs(r0, c0, (r0 + r1) / 2, (c0 + c1) / 2),
          dfs(r0, (c0 + c1) / 2, (r0 + r1) / 2, c1),
          dfs((r0 + r1) / 2, c0, r1, (c0 + c1) / 2),
          dfs((r0 + r1) / 2, (c0 + c1) / 2, r1, c1)
      );
    };

    return dfs(0, 0, n, n);
  }
};

int main(){
    vector<vector<int>> grid = {
        {1,1,0,0},{1,1,0,0},{0,0,1,1},{0,0,1,1}};
    Node *root = Solution::construct(grid);
    return 0;
}
