//lc 658
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pivot = binarySearch(arr,x);
        int left = pivot, right = pivot+1;
        deque<int> outcome;
        vector<int> res;
        for(int i = 0; i < k; ++i) {
            if(left >= 0 && right < arr.size()) {
                int diff_left = abs(arr[left]-x);
                int diff_right = abs(arr[right]-x);
                if(diff_left <= diff_right) 
                    outcome.push_front(arr[left--]);
                else
                    outcome.push_back(arr[right++]);
            }
            else if(left >= 0)
                outcome.push_front(arr[left--]);
            else if(right < arr.size())
                outcome.push_back(arr[right++]);
        }
        std::move(std::begin(outcome), std::end(outcome), std::back_inserter(res));
        return res;
    }
    static int binarySearch(vector<int>& arr, int key) {
        int left = 0, right = arr.size()-1;
        while(left <= right) {
            int mid = left+(right-left)/2;
            if(arr[mid] == key)
                return mid;
            else if(arr[mid] < key)
                left = mid+1;
            else
                right = mid-1;
        }
        if(left > 0)
            return left-1;
        return left;
    }
};
