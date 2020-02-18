//lc 89
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(size_t i = 0; i < (1<<n); ++i) {
            res.push_back(i^(i>>1));
        }
        return res;
    }
};