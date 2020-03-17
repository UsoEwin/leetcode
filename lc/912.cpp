//lc 912
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        qSort(nums,left,right);
        return nums;
    }
private:
    void qSort(vector<int> &nums, int left, int right) {
        if(left < right) {
            int mid = partition(nums,left,right);
            qSort(nums,left,mid-1);
            qSort(nums,mid+1,right);
        }
        return;
    }
    int partition(vector<int> &nums, int left, int right) {
        int pivot_idx = left+(right-left)/2;
        swap(nums,pivot_idx,right);
        int i = left-1;
        for(int j = left; j < right; ++j) {
            if(nums[j] <= nums[right]) {
                i++;
                swap(nums,i,j);
            }
        }
        swap(nums,i+1,right);
        return i+1;
    }
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
};