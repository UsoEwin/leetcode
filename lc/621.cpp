//lc 621
class Solution {
public:
    struct comp {
        bool operator () (const pair<int,int> &a, const pair<int,int> &b) {
            return a.second < b.second;
        }
    };
    int leastInterval(vector<char>& tasks, int k) {
        int res = 0;
        unordered_map<int,int> freq_cnt;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> max_heap;
        for(auto x:tasks)
            freq_cnt[x]++;
        for(auto x:freq_cnt)
            max_heap.push(x);
        
        while(!max_heap.empty()) {
            int n = k+1;
            vector<pair<int,int>> wait_list;
            for(; n > 0 && !max_heap.empty(); --n) {
                auto curr = max_heap.top();
                max_heap.pop();
                if(curr.second > 1) {
                    curr.second--;
                    wait_list.push_back(curr);
                }
                res++;
            }
            for(auto x:wait_list)
                max_heap.push(x);
            if(!max_heap.empty())
                res += n;
        }
        return res;
    }
};