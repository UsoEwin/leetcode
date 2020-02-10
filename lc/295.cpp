//lc 295
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int,vector<int>,less<int>> max_q;
    priority_queue<int,vector<int>,greater<int>> min_q;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_q.empty() || num <= max_q.top())
            max_q.push(num);
        else
            min_q.push(num);
        //make max_q has one more element than min_q or equal
        if(max_q.size() > min_q.size()+1) {
            min_q.push(max_q.top());
            max_q.pop();
        }
        else if(min_q.size() > max_q.size()) {
            max_q.push(min_q.top());
            min_q.pop();
        }
        return;
    }

    double findMedian() {
        if(max_q.size() == min_q.size())
            return max_q.top()/2.0+min_q.top()/2.0;
        else
            return max_q.top();
    }
};