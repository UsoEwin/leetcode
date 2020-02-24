//lc 260
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n1xn2 = 0;
        for(auto x:nums)
            n1xn2 ^= x;
        int lowest_bit = 1;
        while((lowest_bit&n1xn2) == 0)
            lowest_bit <<= 1;
        int num1 = 0, num2 = 0;
        for(auto x:nums) {
            if((x&lowest_bit) == 0)
                num1 ^= x;
            else
                num2 ^= x;
        }
        return vector<int>({num1,num2});
    }
};