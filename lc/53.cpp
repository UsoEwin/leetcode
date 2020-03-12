//lc 53
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_val = nums[0], sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum = max(nums[i],nums[i]+sum);
            max_val = max(max_val,sum);
        }
        return max_val;
    }
};

