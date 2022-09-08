#include <bits/stdc++.h>

using namespace std;

class UF {
  vector<int> id, size;
 public:
  UF(int n): id(n), size(n, 1) {
    iota(id.begin(), id.end(), 0); // iota函数可以把数组初始化为0到n-1
  }
  int find(int p) {
    while (p != id[p]) {
      id[p] = id[id[p]]; // 路径压缩，使得下次查找更快
      p = id[p];
    }
    return p;
  }
  void connect(int p, int q) {
    int i = find(p), j = find(q);
    if (i != j) {
// 按秩合并：每次合并都把深度较小的集合合并在深度较大的集合下面
      if (size[i] < size[j]) {
        id[i] = j;
        size[j] += size[i];
      } else {
        id[j] = i;
        size[i] += size[j];
      } } }
  bool isConnected(int p, int q) {
    return find(p) == find(q);
  }
};