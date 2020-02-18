//lc 47
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size());
        vector<int> curr_res;
        sort(nums.begin(),nums.end());
        for(auto x:used)
            x = false;
        search(res,nums,curr_res,used);
        return res;
    }
private:
    static void search(vector<vector<int>>& res, vector<int>& nums, vector<int>& curr_res, vector<bool> &used) {
        if(curr_res.size() == nums.size()) {
            res.push_back(curr_res);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(used[i])
                continue;
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false) //used[i-1] == false makes sure only run once on dups
                continue;
            curr_res.push_back(nums[i]);
            used[i] = true;
            search(res,nums,curr_res,used);
            curr_res.pop_back();
            used[i] = false;
        }
        return;
    }
};
