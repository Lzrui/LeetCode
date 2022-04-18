//
// Created by l50021384 on 2022/4/6.
//
#include<vector>
using namespace std;
//深度优先搜索
class Solution {
public:
    static vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        int number = 1;
        for (int i = 0; i < n; i++) {
            ret[i] = number;
            if (number * 10 <= n) {
                number *= 10;
            } else {
                while (number % 10 == 9 || number + 1 > n) {
                    number /= 10;
                }
                number++;
            }
        }
        return ret;
    }
};

int main(){
    int n = 13;
    vector<int> res = Solution::lexicalOrder(n);
    return 0;
}
