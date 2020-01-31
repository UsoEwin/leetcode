class AllMissingNumbers {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    vector<int> missingNumbers;
    // TODO: Write your code here
    int i = 0;
    while(i < nums.size()) {
      int j = nums[i] - 1;
      if(nums[i] != nums[j])
        swap(nums,i,j);
      else
        i++;
    }
    for(int i = 0; i < nums.size(); ++i)
      if(i != nums[i]-1)
        missingNumbers.push_back(i+1);
    return missingNumbers;
  }
 private:
  static void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    return;
  }
};