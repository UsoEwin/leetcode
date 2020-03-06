//lc 767
class Solution {
    struct comp{
        bool operator () (const pair<char,int> &a, const pair<char,int> &b) {
            return a.second < b.second;
        }
    };
public:
    string reorganizeString(string S) {
        string res = "";
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp> max_heap;
        unordered_map<char,int> dict;
        for(auto x:S)
            dict[x]++;
        for(auto x:dict)
            max_heap.push(x);
        pair<char,int> prev(-1,-1);
        while(!max_heap.empty()) {
            auto curr = max_heap.top();
            max_heap.pop();
            if(prev.second > 0)
                max_heap.push(prev);
            res += curr.first;
            curr.second--;
            prev = curr;
        }
        return S.size() == res.size() ? res : "";
    }
};