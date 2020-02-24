//lc 1009
class Solution {
public:
    int bitwiseComplement(int n) {
        int set_bits = 0, res = n;
        if(n == 0) return 1;
        while(n > 0)
          n >>= 1, set_bits++;
        int mask = (1 << set_bits)-1;
        return mask ^ res;
    }
};
