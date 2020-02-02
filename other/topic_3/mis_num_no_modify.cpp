class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        }while(slow != fast);
        //find len
        int cyc_len = 0, curr = slow;
        do {
            curr = nums[curr];
            cyc_len++;
        }while(curr != slow);
        //find start pt
        //f(x) = f(x+T)
        int ptr1 = 0, ptr2 = 0;
        while(cyc_len > 0) {
            cyc_len--;
            ptr1 = nums[ptr1];
        }
        while(ptr1 != ptr2) {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }
        return ptr1;
    }
};