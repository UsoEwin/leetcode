//lc 1200
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        int min_diff = INT_MAX;
        for(int i = 0; i < arr.size()-1; ++i) {
            min_diff = min(abs(arr[i+1]-arr[i]),min_diff);
        }
        for(int i = 0; i < arr.size()-1; ++i) {
            if(abs(arr[i+1]-arr[i]) == min_diff)
                res.push_back(vector<int>({arr[i],arr[i+1]}));
        }
        return res;
    }
};