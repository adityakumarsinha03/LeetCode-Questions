class DiningPhilosophers {
    mutex forks[5];
public:
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
            int left = philosopher % 5;
			int right = (philosopher + 1) % 5;
        
			if (philosopher % 2)
				swap(left, right);
//Some philosophers take a fork by right hand, some philosophers takes by left hand. We prevent circular deadlock by this strategy.
        
        
			lock_guard left_lock(forks[left]);
			lock_guard right_lock(forks[right]);
        
			pickRightFork();
			pickLeftFork();
			eat();
			putLeftFork();
			putRightFork();
	 }
};