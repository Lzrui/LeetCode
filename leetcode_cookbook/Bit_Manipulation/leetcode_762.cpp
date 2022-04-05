//
// Created by lzr on 2022/4/5.
#include <vector>
#include <iostream>
using namespace std;
//数学+位运算
//class Solution {
//    bool isPrime(int x) {
//        if (x < 2) {
//            return false;
//        }
//        for (int i = 2; i * i <= x; ++i) {
//            if (x % i == 0) {
//                return false;
//            }
//        }
//        return true;
//    }
//
//public:
//    int countPrimeSetBits(int left, int right) {
//        int ans = 0;
//        for (int x = left; x <= right; ++x) {
//            if (isPrime(__builtin_popcount(x))) {
//                ++ans;
//            }
//        }
//        return ans;
//    }
//};
//判断质数优化
class Solution {
public:
    static int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int x = left; x <= right; ++x) {
            if ((1 << __builtin_popcount(x)) & 665772) {
                ++ans;
            }
        }
        return ans;
    }
};
int main(){
    int left = 6, right = 10;
    cout << Solution::countPrimeSetBits(left,right) << endl;
    return 0;
}
