using namespace std;

#include <iostream>
#include <vector>

class CyclicSort {
 public:
  static void sort(vector<int> &nums) {
    // TODO: Write your code here    
    int i = 0;
    while(i < nums.size()) {
      int j = nums[i]-1;
      if(nums[i] != nums[j]) {
        swap(nums,i,j);
      }
      else
        i++;
    }
    return;
  }
 private:
  static void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    return;
  }
};