class Solution {
public:
    struct compGreater {
        bool operator () (const vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        }
    };
    struct compLess {
        bool operator () (const vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        }
    };
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() < 1) return 0;
        sort(intervals.begin(),intervals.end(),compLess());
        priority_queue<vector<int>, vector<vector<int>>, compGreater> min_heap;
        int min_size = 0;
        for(auto x : intervals) {
            while(!min_heap.empty() && x[0] >= min_heap.top()[1])
                min_heap.pop();
            min_heap.push(x);
            min_size = max((int)min_heap.size(), min_size);
        }
        return min_size;
    }
};