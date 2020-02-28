//lc 34
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res({-1,-1});
        int left = 0, right = nums.size()-1, left_idx = -1, right_idx = -1;
        while(left <= right) {
            int mid = left+((right-left)>>1);
            if(nums[mid] < target)
                left = mid+1;
            else if(nums[mid] > target)
                right = mid-1;
            else {
                left_idx = mid;
                right = mid-1; //search left again
            }
        }
        left = 0, right = nums.size()-1;
        while(left <= right) {
            int mid = left+((right-left)>>1);
            if(nums[mid] < target)
                left = mid+1;
            else if(nums[mid] > target)
                right = mid-1;
            else {
                right_idx = mid;
                left = mid+1; //search right again
            }
        }
        res[0] = left_idx, res[1] = right_idx;
        return res;
    }
};