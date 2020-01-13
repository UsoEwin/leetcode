class MissingNumber {
 public:
  static int findMissingNumber(vector<int> &nums) {
    // TODO: Write your code here
    int i = 0;
    while(i < nums.size()) {
      int j = nums[i];
      if(j < nums.size() && nums[j] != nums[i])
        swap(nums,i,j);
      else
        i++;
    }
    for(int i = 0; i < nums.size(); ++i)
      if(nums[i] != i)
        return i;
    return nums.size();
  }
 private:
  static void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    return;
  }
};
