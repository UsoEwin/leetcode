//lc 480
//multiset, a slightly better solution but still bad
class Solution {
public:
vector<double> medianSlidingWindow(vector<int>& nums, int k)
{
    vector<double> res;
    multiset<int> lo,hi;
    for(int i = 0; i < nums.size(); ++i) {
        if(i >= k) {
            if(nums[i-k] <= *lo.rbegin())
                lo.erase(lo.find(nums[i-k]));
            else
                hi.erase(hi.find(nums[i-k]));
        }
        if(!lo.empty() && nums[i] <= *lo.rbegin())
            lo.insert(nums[i]);
        else
            hi.insert(nums[i]);
        //adjust
        if(hi.size() > lo.size()) {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }        
        else if(lo.size() > hi.size()+1) {
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));
        }
        
        if(i >= k-1)
            res.push_back(k & 1 ? *lo.rbegin() : ((double)(*lo.rbegin()) + (double)(*hi.begin())) * 0.5);
    }
    return res;
    }
};