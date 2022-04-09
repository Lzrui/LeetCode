//
// Created by l50021384 on 2022/4/6.
//
#include <iostream>
using namespace std;
//反向计算
class Solution {
public:
    static bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx > sx && ty > sy && tx != ty){
            if(tx > ty) tx %= ty;
            else ty %= tx;
        }
        if(tx == sx && ty == sy)
            return true;
        else if(tx == sx && ty > sy)
            return (ty - sy) % sx == 0;
        else if(tx > sx && ty == sy)
            return (tx - sx) % sy == 0;
        else
            return false;
    }
};
int main(){
  cout << Solution::reachingPoints(1,1,3,5) << endl;
  return 0;
}



