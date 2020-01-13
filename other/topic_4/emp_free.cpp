/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
public:
    struct compStart {
        bool operator () (const pair<Interval,pair<int,int>>& a, pair<Interval,pair<int,int>>& b) {
            return a.first.start > b.first.start;
        }
    };
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res;
        if(schedule.size() < 1) return res;
        priority_queue <pair<Interval,pair<int,int>>,vector<pair<Interval,pair<int,int>>>,compStart> p_q;
        for(int i = 0; i < schedule.size(); ++i)
            p_q.push(make_pair(schedule[i][0],make_pair(i,0)));
        auto prev_intv = p_q.top().first;
        while(!p_q.empty()) {
            auto curr_q = p_q.top();
            p_q.pop();
            if(curr_q.first.start > prev_intv.end) {
                res.push_back(Interval(prev_intv.end,curr_q.first.start));
                prev_intv = curr_q.first;
            }
            else {
                if(curr_q.first.end > prev_intv.end) {
                    prev_intv = curr_q.first;
                }
            }
            int i = curr_q.second.first, j = curr_q.second.second;
            if(++j < schedule[i].size())
                p_q.push(make_pair(schedule[i][j],make_pair(i,j)));
        }
        return res;
    }
};