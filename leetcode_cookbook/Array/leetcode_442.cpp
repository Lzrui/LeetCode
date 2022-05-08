//
// Created by lzr on 2022/5/4.
//
#include <bits/stdc++.h>
using namespace std;
//将元素交换到指定位置
//class Solution {
//public:
//    static vector<int> findDuplicates(vector<int>& nums) {
//        vector<int> res;
//        int n = nums.size();
//        for(int i = 0;i<n;++i){
//            while(nums[i] != nums[nums[i]-1]){
//                swap(nums[i],nums[nums[i]-1]);
//            }
//        }
//        for(int i = 0;i<n;++i) {
//            if(nums[i]!=i+1)
//                res.emplace_back(nums[i]);
//        }
//        return res;
//    }
//};
//使用正负号作为标记
class Solution {
public:
    static vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int x = abs(nums[i]);
            if (nums[x - 1] > 0) {
                nums[x - 1] = -nums[x - 1];
            }
            else {
                ans.push_back(x);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,1};
    vector<int> res = Solution::findDuplicates(nums);
    return 0;
}
