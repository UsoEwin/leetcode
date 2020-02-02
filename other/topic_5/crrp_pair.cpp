class FindCorruptNums {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    // TODO: Write your code here
    int i = 0;
    while(i < nums.size()) {
      int j = nums[i]-1;
      if(nums[i] != nums[j])
        swap(nums,i,j);
      else
        ++i;
    }
    vector<int> res;
    for(int i = 0; i < nums.size(); ++i) {
      if(nums[i]-1 != i) {
        res.push_back(i+1);
        res.push_back(nums[i]);
      }
    }
    return res;
  }
 private:
  static void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    return;
  }
};