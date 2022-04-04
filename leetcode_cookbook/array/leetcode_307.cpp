#include <vector>
#include <iostream>
using namespace std;
//线段树
//class NumArray {
//private:
//    vector<int> segmentTree;
//    int n;
//
//    void build(int node, int s, int e, vector<int> &nums) {
//        if (s == e) {
//            segmentTree[node] = nums[s];
//            return;
//        }
//        int m = s + (e - s) / 2;
//        build(node * 2 + 1, s, m, nums);
//        build(node * 2 + 2, m + 1, e, nums);
//        segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
//    }
//
//    void change(int index, int val, int node, int s, int e) {
//        if (s == e) {
//            segmentTree[node] = val;
//            return;
//        }
//        int m = s + (e - s) / 2;
//        if (index <= m) {
//            change(index, val, node * 2 + 1, s, m);
//        } else {
//            change(index, val, node * 2 + 2, m + 1, e);
//        }
//        segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
//    }
//
//    int range(int left, int right, int node, int s, int e) {
//        if (left == s && right == e) {
//            return segmentTree[node];
//        }
//        int m = s + (e - s) / 2;
//        if (right <= m) {
//            return range(left, right, node * 2 + 1, s, m);
//        } else if (left > m) {
//            return range(left, right, node * 2 + 2, m + 1, e);
//        } else {
//            return range(left, m, node * 2 + 1, s, m) + range(m + 1, right, node * 2 + 2, m + 1, e);
//        }
//    }
//
//public:
//    NumArray(vector<int>& nums) : n(nums.size()), segmentTree(nums.size() * 4) {
//        build(0, 0, n - 1, nums);
//    }
//
//    void update(int index, int val) {
//        change(index, val, 0, 0, n - 1);
//    }
//
//    int sumRange(int left, int right) {
//        return range(left, right, 0, 0, n - 1);
//    }
//};
//树状数组
class NumArray {
private:
    vector<int> tree;
    vector<int> &nums;

    int lowBit(int x) {
        return x & -x;
    }

    void add(int index, int val) {
        while (index < tree.size()) {
            tree[index] += val;
            index += lowBit(index);
        }
    }

    int prefixSum(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= lowBit(index);
        }
        return sum;
    }

public:
    NumArray(vector<int>& nums) : tree(nums.size() + 1), nums(nums) {
        for (int i = 0; i < nums.size(); i++) {
            add(i + 1, nums[i]);
        }
    }

    void update(int index, int val) {
        add(index + 1, val - nums[index]);
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }
};

int main(){
    vector<int> nums = {1,3,5};
    NumArray test(nums);
    test.update(1,10);
    cout << test.sumRange(0,2) << endl;
    return 0;
}