
class Foo {
    mutex m;
    condition_variable cv;
    int turn;
public:
    Foo() {
        turn= 1;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn =2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m);
         while(turn!=2){
            cv.wait(lock);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        turn= 3;
        //lock.unlock(); optional as otherwise it gets unlocked in its destructor
        cv.notify_all();      
        
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m);
        while(turn!=3){
            cv.wait(lock);
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        //lock.unlock(); 
    }
};