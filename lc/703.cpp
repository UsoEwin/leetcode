//lc 703
class KthLargest {
    priority_queue<int,vector<int>,greater<int>> min_q;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto x:nums)
            add(x);
    }
    
    int add(int val) {
        min_q.push(val);
        if((int)min_q.size() > this->k)
            min_q.pop();
        return min_q.top();
    }
};