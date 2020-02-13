//lc 78
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> set;
        res.push_back(set);
        for(int i = 0; i < nums.size(); ++i) {
            int n = res.size();
            for(int j = 0; j < n; ++j) {
                set = res[j];
                set.push_back(nums[i]);
                res.push_back(set);
            }
        }
        return res;
    }
};