//lc 480
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        //two heap
        priority_queue<int,vector<int>,less<int>> max_q;
        priority_queue<int,vector<int>,greater<int>> min_q;
        unordered_map<int,int> expired;
        vector<double> res;
        
        for(int i = 0; i < k; ++i)
            max_q.push(nums[i]);
        for(int i = 0; i < k/2; ++i) {
            min_q.push(max_q.top());
            max_q.pop();
        }
        int i = k;
        while(i < nums.size()) {
            res.push_back(k&1 ? max_q.top() : max_q.top()/2.0 + min_q.top()/2.0);
            int out_val = nums[i-k];
            int in_val = nums[i++];
            int balance = out_val <= max_q.top() ? 1 : -1; //1--min_q has more, -1--max_q has more
            expired[out_val]++;
            if(!max_q.empty() && in_val <= max_q.top())
                max_q.push(in_val), balance--;
            else
                min_q.push(in_val), balance++;
            if(balance < 0) { //max_q has more
                min_q.push(max_q.top());
                max_q.pop();
                balance++;
            }
            if(balance > 0) { //min_q has more
                max_q.push(min_q.top());
                min_q.pop();
                balance--;
            }
            while(!max_q.empty() && expired[max_q.top()]) {
                expired[max_q.top()]--;
                max_q.pop();
            }
            while(!min_q.empty() && expired[min_q.top()]) {
                expired[min_q.top()]--;
                min_q.pop();
            }
        }
        res.push_back(k&1 ? max_q.top() : max_q.top()/2.0 + min_q.top()/2.0);
        return res;
    }
};