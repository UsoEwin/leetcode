//lc 42
//dp
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 1)
            return 0;
        int size = height.size(), res = 0;
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        
        for(int i = 1; i < size; ++i)
            left_max[i] = max(left_max[i-1],height[i]);
        
        right_max[size-1] = height[size-1];
        
        for(int i = size-2; i >= 0; --i)
            right_max[i] = max(right_max[i+1],height[i]);
        
        for(int i = 1; i < size-1; ++i) {
            res +=  min(left_max[i],right_max[i])-height[i];
        }
        
        return res;
    }
};
//two ptr
//unlike the dp, we don't need the absolte max from left and right
//for left we just need to know absolute max from left, similar for right
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 1)
            return 0;
        int left_max = 0, right_max = 0;
        int left = 0, right = height.size()-1, res = 0;
        while(left < right) {
            if(height[left] > left_max)
                left_max = height[left];
            if(height[right] > right_max)
                right_max = height[right];
            if(left_max < right_max) {
                int val = max(0,left_max-height[left]);
                res += val;
                left++;
            }
            else {
                int val = max(0,right_max-height[right]);
                res += val;
                right--;
            }
        }
        return res;
    }
};
