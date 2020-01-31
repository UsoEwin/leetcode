class FindDuplicate {
 public:
  static int findNumber(vector<int> &nums) {
    // TODO: Write your code here
    int i = 0;
    while(i < nums.size()) {
      if(nums[i] != i+1) {
        int j = nums[i] - 1;
        if(nums[i] != nums[j])
          swap(nums,i,j);
        else
          return nums[i];
      }
      else
        ++i;
    }
    return -1;
  }
 private:
  static void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    return;
  }
};