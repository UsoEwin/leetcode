//lc 215
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        return qFind(nums,0,nums.size()-1,k);
    }
private:
    static int qFind(vector<int> &nums, int left, int right, int k) {
        int pivot = partition(nums,left,right);
        if(k-1 == pivot)
            return nums[pivot];
        else if(k-1 > pivot)
            return qFind(nums,pivot+1,right,k);
        else
            return qFind(nums,left,pivot-1,k);
    }
    static int partition(vector<int> &nums, int left, int right) {
        if(left == right)
            return left;
        int index = left+(right-left)/2;
        swap(nums,index,right);
        int i = left;
        for(int j = left; j < right; ++j) {
            if(nums[j] >= nums[right]) {
                swap(nums,i++,j);
            }
        }
        swap(nums,i,right);
        return i;
    }
    static void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
};