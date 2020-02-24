//lc 137
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seen_once = 0, seen_twice = 0;
        for(auto x:nums) {
            seen_once = ~seen_twice & (seen_once ^ x);
            seen_twice = ~seen_once & (seen_twice ^ x);
        }
        return seen_once;
    }
};