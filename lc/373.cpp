//lc 373
class Solution {
    struct compSum {
        bool operator() (const vector<int> &a, const vector<int> &b) {
            return a[0]+a[1] < b[0]+b[1];
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> max_heap;
        for(int i = 0; i < nums1.size() && i < k; ++i) {
            for(int j = 0; j < nums2.size() && j < k; ++j) {
                if(max_heap.size() < k) {
                    max_heap.push_back(vector<int>({nums1[i],nums2[j]}));
                    push_heap(max_heap.begin(),max_heap.end(),compSum());
                }
                else {
                    auto curr = max_heap.front();
                    if(curr[0]+curr[1] > nums1[i]+nums2[j]) {
                        pop_heap(max_heap.begin(),max_heap.end(),compSum());
                        max_heap.pop_back();
                        max_heap.push_back(vector<int>({nums1[i],nums2[j]}));
                        push_heap(max_heap.begin(),max_heap.end(),compSum());
                    }
                    else
                        break;
                }
            }
        }
        return max_heap;
    }
};