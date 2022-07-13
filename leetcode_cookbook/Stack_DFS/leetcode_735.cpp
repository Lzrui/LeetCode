#include<bits/stdc++.h>
using namespace std;

class Solution {
 public:
  static vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> st;
    for (auto aster : asteroids) {
      bool alive = true;
      while (alive && aster < 0 && !st.empty() && st.back() > 0) {
        alive = st.back() < -aster; // aster 是否存在
        if (st.back() <= -aster) {  // 栈顶行星爆炸
          st.pop_back();
        }
      }
      if (alive) {
        st.push_back(aster);
      }
    }
    return st;
  }
};



int main(){
  vector<int> asteroids = {5,10,-5};
  vector<int> res = Solution::asteroidCollision(asteroids);
  return 0;
}