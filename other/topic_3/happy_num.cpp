class Solution {
public:
    bool isHappy(int n) {
        int fast = n, slow = n;
        do {
            fast = compNext(compNext(fast));
            slow = compNext(slow);
        } while(fast != slow);
        return slow == 1;
    }
private:
    int compNext(int n) {
        int sum = 0;
        while(n > 0) {
            int digit = n % 10;
            sum += digit*digit;
            n /= 10;
        }
        return sum;
    }
};