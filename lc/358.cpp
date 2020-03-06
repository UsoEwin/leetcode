//lc 358
class Solution {
    struct comp{
        bool operator () (const pair<char,int> &a, const pair<char,int> &b) {
            return a.second < b.second; //max heap
        }
    };
public:
    string rearrangeString(string s, int k) {
        if(k <= 1)
            return s;
        string res = "";
        unordered_map<char,int> dict;
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp> max_heap;
        queue<pair<char,int>> letters;
        for(auto x:s)
            dict[x]++;
        for(auto x:dict)
            max_heap.push(x);
        while(!max_heap.empty()) {
            auto curr = max_heap.top();
            max_heap.pop();
            res += curr.first;
            curr.second -= 1;
            letters.push(curr);
            if(letters.size() >= k) {
                auto entry = letters.front();
                letters.pop();
                if(entry.second > 0)
                    max_heap.push(entry);
            }
        }
        return res.size() == s.size() ? res : "";
    }
};