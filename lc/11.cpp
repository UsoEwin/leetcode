//lc 11
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, max_area = 0;
        while(left < right) {
            int area = (right-left)*min(height[left],height[right]);
            max_area = max(area,max_area);
            if(height[left] > height[right])
                right--;
            else
                left++;
        }
        return max_area;
    }
};