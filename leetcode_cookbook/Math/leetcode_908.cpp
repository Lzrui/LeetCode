//
// Created by lzr on 2022/4/30.
//
//
// Created by l50021384 on 2022/4/6.
//
#include <bits/stdc++.h>
using namespace std;
//数学
class Solution {
public:
    static int smallestRangeI(vector<int>& nums, int k) {
        auto [min,max] = minmax_element(nums.begin(),nums.end());
        return *max - *min<= 2 * k?0:*max-*min - 2*k;
    }
};
int main(){
    vector<int> a = {1,3,6};
    int k =3;
    cout << Solution::smallestRangeI(a,3) << endl;
    return 0;
}



