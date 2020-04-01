//lc 139
//tabulation
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        vector<bool> dp(s.size()+1,false);
        for(auto x:wordDict)
            dict.insert(x);
        dp[0] = true;
        for(int i = 1; i <= s.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(dp[j] && dict.find(s.substr(j,i-j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};