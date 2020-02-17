//lc 90
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> set;
        res.push_back(set);
        sort(nums.begin(),nums.end());
        int start_idx = 0, end_idx = 0;
        for(int i = 0; i < nums.size(); ++i) {
            start_idx = 0;
            if(i > 0 && nums[i] == nums[i-1])
                start_idx = end_idx+1;
            end_idx = res.size()-1;
            while(start_idx <= end_idx) {
                set = res[start_idx++];
                set.push_back(nums[i]);
                res.push_back(set);
            }
        }
        return res;
    }
};