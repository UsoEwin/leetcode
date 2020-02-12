//lc 436
class Solution {
public:
    struct compEnd{
        bool operator()(const pair<vector<int>,int> &a, const pair<vector<int>,int> &b) {
            return a.first[1] < b.first[1];
        }
    };
    struct compStart{
        bool operator()(const pair<vector<int>,int> &a, const pair<vector<int>,int> &b) {
            return a.first[0] < b.first[0];
        }
    };
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> res(n);
        priority_queue<pair<vector<int>,int>,vector<pair<vector<int>,int>>,compEnd> max_end;
        priority_queue<pair<vector<int>,int>,vector<pair<vector<int>,int>>,compStart> max_start;
        for(int i = 0; i < n; ++i) {
            max_end.push(make_pair(intervals[i],i));
            max_start.push(make_pair(intervals[i],i));
        }
        for(int i = 0; i < n; ++i) {
            auto top_end = max_end.top();
            max_end.pop();
            res[top_end.second] = -1;
            if(max_start.top().first[0] >= top_end.first[1]) {
                auto top_start = max_start.top();
                max_start.pop();
                while(!max_start.empty() && max_start.top().first[0] >= top_end.first[1]) {
                    top_start = max_start.top();
                    max_start.pop();
                }
                res[top_end.second] = top_start.second;
                max_start.push(top_start);
            }
        }
        return res;
    }
};