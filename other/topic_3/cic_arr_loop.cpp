class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int slow = i, fast = i, dir = nums[i] >= 0;
            do {
                slow = getNextIdx(nums,dir,slow);
                fast = getNextIdx(nums,dir,fast);
                if(fast != -1)
                    fast = getNextIdx(nums,dir,fast);
            } while(slow != -1 && fast != -1 && slow != fast);
            if(slow != -1 && fast == slow)
                return true;
        }
        return false;
    }
private:
    int getNextIdx(vector<int>& nums, int dir, int curr_idx) {
        int curr_dir = nums[curr_idx] >= 0;
        if(curr_dir != dir)
            return -1;
        int next_idx = (curr_idx + nums[curr_idx] + nums.size()) % nums.size();
        if(next_idx == curr_idx)
            return -1;
        return next_idx;
    }
};