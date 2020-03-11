//lc 1114
#include <semaphore.h>
class Foo {
    sem_t first_done;
    sem_t second_done;
public:
    Foo() {
        sem_init(&first_done,0,0);
        sem_init(&second_done,0,0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&first_done);
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        sem_wait(&first_done);
        printSecond();
        sem_post(&second_done);
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        sem_wait(&second_done);
        printThird();
    }
};