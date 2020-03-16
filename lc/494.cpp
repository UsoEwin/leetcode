//lc 494
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(S > 1000) return 0;
        vector<vector<int>> dp(nums.size(),vector<int>(2001,0));
        dp[0][nums[0]+1000] = 1;
        dp[0][-nums[0]+1000] += 1; //for the case num[0] = 0
        for(int i = 1; i < nums.size(); ++i) {
            for(int j = -1000; j <= 1000; ++j ) {
                if(dp[i-1][j+1000] > 0) {
                    dp[i][j-nums[i]+1000] += dp[i-1][j+1000];
                    dp[i][j+nums[i]+1000] += dp[i-1][j+1000];
                }
            }
        }
        //here j is the sum, dp[i][j+1000] is the ways using num[i] to build j
        return dp[nums.size()-1][S+1000];
    }
};