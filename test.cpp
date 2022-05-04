//
// Created by lzr on 2022/5/4.
//
#include <bits/stdc++.h>
using namespace std;
//模拟加队列
//class Solution {
//public:
//    static int findTheWinner(int n, int k) {
//        queue<int> qu;
//        for (int i = 1; i <= n; i++) {
//            qu.emplace(i);
//        }
//        while (qu.size() > 1) {
//            for (int i = 1; i < k; i++) {
//                qu.emplace(qu.front());
//                qu.pop();
//            }
//            qu.pop();
//        }
//        return qu.front();
//    }
//};
//数学+递归
class Solution {
public:
    static int findTheWinner(int n, int k) {
        if (n == 1) {
            return 1;
        }
        return (k + findTheWinner(n - 1, k) - 1) % n + 1;
    }
};

int main(){
    int n=5,k=2;
    printf("%d\n",Solution::findTheWinner(n,k));
    return 0;
}
