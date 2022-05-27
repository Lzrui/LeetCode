#include<bits/stdc++.h>

using namespace std;
//基于快速排序的选择方法
class Solution {
 public:
  int quickSelect(vector<int> &nums,int l,int r,int target){
    int idx = Randpartition(nums,l,r);
    if(idx == target) return nums[idx];
    return idx < target?quickSelect(nums,idx+1,r,target):quickSelect(nums,l,idx-1,target);
  }

  int Randpartition(vector<int> &nums,int l,int r){
    int i = rand()%(r-l+1)+l;
    swap(nums[i],nums[l]);
    return partition(nums,l,r);
  }

  int partition(vector<int> &nums,int l,int r){
    int key = nums[l];
    int first = l,last = r;
    while(first < last){
      while(first < last && nums[last] >= key)
        --last;
      nums[first] = nums[last];
      while(first < last && nums[first] <= key)
        ++first;
      nums[last] = nums[first];
    }
    nums[first] = key;
    return first;
  }

  int findKthLargest(vector<int>& nums, int k) {
    srand((unsigned)time(nullptr));
    return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
  }
};
//基于堆排序的选择方法
//class Solution {
// public:
//  void MaxHeapify(vector<int> &nums,int idx,int heapsize){
//    int l = 2*idx+1, r = 2*idx+2, max = idx;
//    if(l < heapsize && nums[l] > nums[max])
//      max = l;
//    if(r < heapsize && nums[r] > nums[max])
//      max = r;
//    if(max != idx) {
//      swap(nums[idx], nums[max]);
//      MaxHeapify(nums,max,heapsize);
//    }
//  }
//
//  void buildMaxHeap(vector<int> &nums,int heapsize){
//    for(int i = heapsize/2;i>=0;--i)
//      MaxHeapify(nums,i,heapsize);
//  }
//
//  int findKthLargest(vector<int>& nums, int k) {
//    int heapsize = nums.size();
//    buildMaxHeap(nums,heapsize);
//    for(int i = 1;i < k;++i){
//      swap(nums[0],nums[heapsize-1]);
//      --heapsize;
//      MaxHeapify(nums,0,heapsize);
//    }
//    return nums[0];
//  }
//};

int main(){
  vector<int> nums = {3,2,3,1,2,4,5,5,6};
  int k = 4;
  Solution test;
  cout << test.findKthLargest(nums,k) << endl;
  return 0;
}