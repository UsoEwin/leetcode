//lc 347
class Solution {
    struct comp {
        bool operator () (const pair<int,int> &a, const pair<int,int> &b) {
            return a.second > b.second;
        }  
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> dict;
        for(auto x:nums) {
            dict[x]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> min_heap;
        for(auto x:dict) {
            min_heap.push(x);
            if(min_heap.size() > k)
                min_heap.pop();
        }
        while(!min_heap.empty()) {
            res.push_back(min_heap.top().first);
            min_heap.pop();
        }
        return res;
    }
};