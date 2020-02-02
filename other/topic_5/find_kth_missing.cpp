class FirstKMissingPositive {
 public:
  static vector<int> findNumbers(vector<int> &nums, int k) {
    vector<int> missingNumbers;
    // TODO: Write your code here
    int i = 0;
    while(i < nums.size()) {
      if(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1])
        swap(nums,i,nums[i]-1);
      else
        ++i;
    }
    unordered_set<int> set;
    for(int i = 0; i < nums.size() && set.size() < k; ++i) {
      if(nums[i]-1 != i) {
        set.insert(nums[i]);
        missingNumbers.push_back(i+1);
      }
    }
    //key step, add more from nums.size()+1
    for(int i = 1; missingNumbers.size() < k; ++i) {
      int candidate = i + nums.size();
      if(set.find(candidate) == set.end()) {
        missingNumbers.push_back(candidate);
      }
    }
    return missingNumbers;
  }
 private:
  static void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    return;
  }
};