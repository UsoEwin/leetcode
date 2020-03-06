//lc 1095
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0, right = mountainArr.length()-1;
        while(left < right) {
            int mid = left+(right-left)/2;
            int val = mountainArr.get(mid), val_next = mountainArr.get(mid+1);
            if(val > val_next)
                right = mid;
            else
                left = mid+1;
        }
        int max_idx = left;
        left = 0, right = max_idx;
        while(left <= right) {
            int mid = left+(right-left)/2;
            int val = mountainArr.get(mid);
            if(target == val)
                return mid;
            else if(target > val)
                left = mid+1;
            else
                right = mid-1;
        }
        left = max_idx+1, right = mountainArr.length()-1;
        while(left <= right) {
            int mid = left+(right-left)/2;
            int val = mountainArr.get(mid);
            if(val == target)
                return mid;
            else if(val < target)
                right = mid-1;
            else
                left = mid+1;
        }
        return -1;
    }
};