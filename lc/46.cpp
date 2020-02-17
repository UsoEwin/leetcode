//lc 46
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums,res,0);
        return res;
    }
private:
    static void backtrack(vector<int> &nums, vector<vector<int>> &res,int fix_slot) {
        if(fix_slot == nums.size()-1) {
            res.push_back(nums);
            return;
        }
        for(int i = fix_slot; i < nums.size(); ++i) {
            swap(nums,fix_slot,i);
            backtrack(nums,res,fix_slot+1);
            swap(nums,fix_slot,i);
        }
        return;
    }
    static void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
};