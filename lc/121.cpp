//lc 121
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int min_pt = prices[0], max_val = 0;
        for(int i = 0; i < prices.size(); ++i) {
            int diff = prices[i]-min_pt;
            min_pt = min(prices[i],min_pt);
            max_val = max(max_val,diff);
        }
        return max_val;
    }
};