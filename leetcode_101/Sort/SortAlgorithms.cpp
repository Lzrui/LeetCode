#include<bits/stdc++.h>

using namespace std;
//暴力枚举

void quicksort_1(vector<int> &nums,int l,int r){
  if( l+1 >= r) return;
  int first = l, last = r-1, key = nums[first];
  while(first < last){
    while(first < last && nums[last] >= key)
      --last;
    nums[first] = nums[last];
    while(first < last && nums[first] <= key)
      ++first;
    nums[last] = nums[first];
  }
  nums[first] = key;
  quicksort_1(nums,first+1,r);
  quicksort_1(nums,l,last);
}

void quicksort_2(vector<int> &nums,int l,int r){
  if( l+1 >= r) return;
  int first = l, last = r-1;
  while(first < last){
    while(first < last && nums[last] >= nums[l])
      --last;
    while(first < last && nums[first] <= nums[l])
      ++first;
    swap(nums[first],nums[last]);
  }
  swap(nums[first],nums[l]);
  quicksort_2(nums,first+1,r);
  quicksort_2(nums,l,last);
}

void quicksort_3(vector<int> &nums,int l,int r){
  if( l+1 >= r) return;
  int first = l, last = r-1;
  int x = nums[last], i = first - 1;
  for (int j = first; j < last; ++j) {
    if (nums[j] <= x) {
      swap(nums[++i], nums[j]);
    }
  }
  swap(nums[i + 1], nums[last]);
  quicksort_3(nums,first+1,r);
  quicksort_3(nums,l,last);
}

void merge_sort(vector<int> &nums, int l, int r, vector<int> &temp){
  if(l+1 >= r) return;
  int m = l+(r-l)/2;
  merge_sort(nums,l,m,temp);
  merge_sort(nums,m,r,temp);
  int p = l, q = m, i = l;
  while(p < m || q < r){
    if(q >= r || (p < m && nums[p] <= nums[q])) {
      temp[i++] = nums[p++];
    }
    else temp[i++] = nums[q++];
  }
  for(i = l;i < r;++i)
    nums[i] = temp[i];
}

void insertion_sort(vector<int> &nums, int n) {
  for(int i = 1;i<n;++i){
    for(int j = i;j>0 && nums[j] < nums[j-1];--j)
      swap(nums[j],nums[j-1]);
  }
}

void bubble_sort(vector<int> &nums, int n) {
  bool swapped;
  for(int i = 1;i<n;++i){
    swapped = false;
    for(int j = 1;j < n-i+1;++j){
      if(nums[j] < nums[j-1]){
        swap(nums[j],nums[j-1]);
        swapped = true;
      }
    }
    if(!swapped)
      break;
  }
}

void selection_sort(vector<int> &nums, int n) {
  int curr;
  for(int i = 0;i < n-1;++i){
    curr = i;
    for(int j = i+1;j < n;++j){
      if(nums[j] < nums[curr])
        curr = j;
    }
    swap(nums[curr],nums[i]);
  }
}


int main(){
  vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
  vector<int> temp(nums.size());
  selection_sort(nums,nums.size());
  return 0;
}