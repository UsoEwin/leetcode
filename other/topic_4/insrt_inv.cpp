class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() < 1)
            return vector<vector<int>>({newInterval});
        vector<vector<int>> res;
        int i = 0;
        while(i < intervals.size() && newInterval[0] > intervals[i][1])
            res.push_back(intervals[i++]);
        while(i < intervals.size() && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i++][1]);
        }
        res.push_back(newInterval);
        while(i < intervals.size())
            res.push_back(intervals[i++]);
        return res;
    }
};