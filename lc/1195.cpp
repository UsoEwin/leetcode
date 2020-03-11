//lc 1195
class FizzBuzz {
private:
    int n;
    atomic<int> cnt;
public:
    FizzBuzz(int n) {
        this->n = n;
        cnt.store(1);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true) {
            int val = cnt.load();
            if(val > n)
                break;
            if(val%3 == 0 && val%5 != 0) {
                printFizz();
                cnt.store(val+1);
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true) {
            int val = cnt.load();
            if(val > n)
                break;
            if(val%3 != 0 && val%5 == 0) {
                printBuzz();
                cnt.store(val+1);
            }
        }        
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true) {
            int val = cnt.load();
            if(val > n)
                break;
            if(val%3 == 0 && val%5 == 0) {
                printFizzBuzz();
                cnt.store(val+1);
            }
        }           
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(true) {
            int val = cnt.load();
            if(val > n)
                break;
            if(val%3 != 0 && val%5 != 0) {
               printNumber(val);
               cnt.store(val+1);
            }
        }           
    }
};