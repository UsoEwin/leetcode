//lc 1115
class FooBar {
private:
    int n;
    atomic<bool> b{true};

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            while(!b.load(std::memory_order_acquire)) {
                std::this_thread::yield();
            }
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            b.store(false,std::memory_order_release);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            while(b.load(std::memory_order_acquire)) {
                std::this_thread::yield();
            }
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            b.store(true,std::memory_order_release);
        }
    }
};