//416. Partition Equal Subset Sum
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = 0;
        for(auto x:nums)
            sum += x;
        if(sum%2 == 1)
            return false;
        int n = nums.size(), s = sum>>1;
        vector<vector<bool>> dp(n,vector<bool>(s+1,false));
        for(int i = 0; i < n; ++i)
            dp[i][0] = true;
        for(int i = 0; i <= s; ++i) {
            if(nums[0] == i)
                dp[0][i] = true;
        }
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j <= s; ++j) {
                bool eva1 = false, eva2 = dp[i-1][j];
                if(j >= nums[i])
                    eva1 = dp[i-1][j-nums[i]];
                dp[i][j] = eva1||eva2;
                if(j == s && dp[i][j])
                    return true;
            }
        }
        return dp[n-1][s];
    }
};