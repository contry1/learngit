// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//



// string::assign
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

//thread1 and thread2 is not order excu

//std::mutex m;
//std::condition_variable cv;
//std::string data;
//bool ready = false;
//bool processed1 = false;
//bool processed2 = false;
//
//void worker_thread1()
//{
//    // Wait until main() sends data
//    std::unique_lock<std::mutex> lk(m);
//    cv.wait(lk, [] {return ready; });
//
//    // after the wait, we own the lock.
//    std::cout << "Worker thread 1 is processing data\n";
//    data += " after processing";
//
//    // Send data back to main()
//    processed1 = true;
//    std::cout << "Worker thread 1 signals data processing completed\n";
//
//    // Manual unlocking is done before notifying, to avoid waking up
//    // the waiting thread only to block again (see notify_one for details)
//    lk.unlock();
//    cv.notify_one();
//}
//
//void worker_thread2()
//{
//    // Wait until main() sends data
//    std::unique_lock<std::mutex> lk(m);
//    cv.wait(lk, [] {return ready; });
//
//    // after the wait, we own the lock.
//    std::cout << "Worker thread 2 is processing data\n";
//    data += " after processing";
//
//    // Send data back to main()
//    processed2 = true;
//    std::cout << "Worker thread 2 signals data processing completed\n";
//
//    // Manual unlocking is done before notifying, to avoid waking up
//    // the waiting thread only to block again (see notify_one for details)
//    lk.unlock();
//    cv.notify_one();
//}
//
//
//
//
//
//int main()
//{
//    std::thread worker1(worker_thread1);
//    std::thread worker2(worker_thread2);
//
//    data = "Example data";
//    // send data to the worker thread
//    {
//        std::lock_guard<std::mutex> lk(m);
//        ready = true;
//        std::cout << "main() signals data ready for processing\n";
//    }
//    cv.notify_all();
//
//    // wait for the worker
//    {
//        std::unique_lock<std::mutex> lk(m);
//        cv.wait(lk, [] {return processed2&& processed1; });//return processed2 ,thread2 first excu;return processed1 ,thread1 first excu;
//    }
//    std::cout << "Back in main(), data = " << data << '\n';
//
//    worker1.join();
//    worker2.join();
//}



////二。交替两个线程
//std::mutex m1;
//std::mutex m2;
//std::condition_variable cv;
//std::string data;
//bool ready1 = false;
//bool ready2 = false;
//bool processed1 = false;
//bool processed2 = false;
//
//void worker_thread1()
//{
//    // Wait until main() sends data
//    std::unique_lock<std::mutex> lk(m1);
//    cv.wait(lk, [] {return ready1; });
//
//    // after the wait, we own the lock.
//    std::cout << "Worker thread 1 is processing data\n";
//    data += " after processing";
//
//    // Send data back to main()
//    processed1 = true;
//    std::cout << "Worker thread 1 signals data processing completed\n";
//
//    // Manual unlocking is done before notifying, to avoid waking up
//    // the waiting thread only to block again (see notify_one for details)
//    lk.unlock();
//    cv.notify_one();
//}
//
//void worker_thread2()
//{
//    // Wait until main() sends data
//    std::unique_lock<std::mutex> lk(m2);
//    cv.wait(lk, [] {return ready2; });
//
//    // after the wait, we own the lock.
//    std::cout << "Worker thread 2 is processing data\n";
//    data += " after processing";
//
//    // Send data back to main()
//    processed2 = true;
//    std::cout << "Worker thread 2 signals data processing completed\n";
//
//    // Manual unlocking is done before notifying, to avoid waking up
//    // the waiting thread only to block again (see notify_one for details)
//    lk.unlock();
//    cv.notify_one();
//}
//
//
//int main()
//{
//    std::thread worker1(worker_thread1);
//    std::thread worker2(worker_thread2);
//
//    data = "Example data";
//    // send data to the worker thread 1
//    {
//        std::lock_guard<std::mutex> lk1(m1);
//        ready1 = true;
//        std::cout << "main() signals data ready for processing to thread1\n";
//    }
//    cv.notify_one();
//    // wait for the worker1
//    {
//        std::unique_lock<std::mutex> lk(m1);
//        cv.wait(lk, [] {return  processed1; });//return processed2 ,thread2 first excu;return processed1 ,thread1 first excu;
//    }
//
//
//
//
//    // send data to the worker thread 2
//    {
//        std::lock_guard<std::mutex> lk2(m2);
//        ready2 = true;
//        std::cout << "main() signals data ready for processing to thread2\n";
//    }
//    cv.notify_one();
//
//    // wait for the worker2
//    {
//        std::unique_lock<std::mutex> lk3(m2);
//        cv.wait(lk3, [] {return processed2 ; });//return processed2 ,thread2 first excu;return processed1 ,thread1 first excu;
//    }
//    std::cout << "Back in main(), data = " << data << '\n';
//
//    worker1.join();
//    worker2.join();
//}


////二。交替两个线程2
std::mutex m1;
//std::mutex m2;//only need one mutex m1
std::condition_variable cv;
std::string data;
bool ready1 = false;
bool ready2 = false;
bool processed1 = false;
bool processed2 = false;

void worker_thread1()
{
    // Wait until main() sends data
    std::unique_lock<std::mutex> lk1(m1);
    cv.wait(lk1, [] {return ready1; });

    // after the wait, we own the lock.
    std::cout << "Worker thread 1 is processing data\n";
    data += " after processing";

    // Send data back to main()
    processed1 = true;
    std::cout << "Worker thread 1 signals data processing completed\n";

    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    lk1.unlock();
    cv.notify_one();
}

void worker_thread2()
{
    // Wait until main() sends data
    std::unique_lock<std::mutex> lk2(m1);
    cv.wait(lk2, [] {return ready2; });

    // after the wait, we own the lock.
    std::cout << "Worker thread 2 is processing data\n";
    data += " after processing";

    // Send data back to main()
    processed2 = true;
    std::cout << "Worker thread 2 signals data processing completed\n";

    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    lk2.unlock();
    cv.notify_one();
}


int main()
{
    std::thread worker1(worker_thread1);
    std::thread worker2(worker_thread2);

    data = "Example data";
    // send data to the worker thread 1
    {
        std::lock_guard<std::mutex> lk1(m1);
        ready1 = true;
        std::cout << "main() signals data ready for processing to thread1\n";
    }
    cv.notify_one();
    // wait for the worker1
    {
        std::unique_lock<std::mutex> lk11(m1);
        cv.wait(lk11, [] {return  processed1; });//return processed2 ,thread2 first excu;return processed1 ,thread1 first excu;
    }




    // send data to the worker thread 2
    {
        std::lock_guard<std::mutex> lk2(m1);
        ready2 = true;
        std::cout << "main() signals data ready for processing to thread2\n";
    }
    cv.notify_one();

    // wait for the worker2
    {
        std::unique_lock<std::mutex> lk22(m1);
        cv.wait(lk22, [] {return processed2; });//return processed2 ,thread2 first excu;return processed1 ,thread1 first excu;
    }
    std::cout << "Back in main(), data = " << data << '\n';

    worker1.join();
    worker2.join();
   
}
















//三。unique_lock lock_guard

//#include <iostream>       // std::cout
//#include <thread>         // std::thread
//#include <mutex>          // std::mutex, std::lock, std::unique_lock
//// std::adopt_lock, std::defer_lock
//std::mutex foo, bar;
//
//void task_a() {
//
//    std::cout << "task a  ago\n";
//    std::lock(foo, bar);         // simultaneous lock (prevents deadlock)
//    std::cout << "task a 2 ago\n";
//    std::unique_lock<std::mutex> lck1(foo, std::adopt_lock);
//    std::unique_lock<std::mutex> lck2(bar, std::adopt_lock);
//    //(2.1) std::adopt_lock： 表示这个互斥量已经被lock了（你必须要把互斥量提前lock了，否则会报异常）
//    //std::adopt_lock 标记的效果就是 “假设调用方 线程已经拥有了互斥的所有权（已经lock（）成功了）；”
//    //通知lock_guard不需要再构造函数中lock这个互斥量了；
//    //unique_lock也可以带std::adopt_lock标记，含义相同，就是不希望再unique_lock()的构造函数中lock这个mutex。
//    //用这个adopt_lock的前提是，你需要自己先把mutex先lock上；
//
//    std::cout << "task a\n";
//    // (unlocked automatically on destruction of lck1 and lck2)
//}
//
//void task_b() {
//    // foo.lock(); bar.lock(); // replaced by:
//    
//    // std::unique_lock<std::mutex> lck1, lck2;
//    //lck1 = std::unique_lock<std::mutex>(bar, std::defer_lock);
//    //lck2 = std::unique_lock<std::mutex>(foo, std::defer_lock);
//
//    std::cout << "task b  ago\n";
//    std::unique_lock<std::mutex> lck1(bar, std::defer_lock);//these is equal to above!
//    std::unique_lock<std::mutex> lck2(foo, std::defer_lock);
//    //(2.3) std::defer_lock
//    //用这个defer_lock的前提是 你不能自己先lock,否则会报异常。
//    //defer_lock的意思 就是 并没有给mutex加锁： 初始化了一个没有加锁的mutex。
//
//    std::cout << "task b 2 ago\n";
//
   //std::lock(lck1, lck2);       // simultaneous lock (prevents deadlock)
//    std::cout << "task b\n";
//    //lck1.unlock(); lck2.unlock();// (unlocked automatically on destruction of lck1 and lck2)
//}
//
////三：unique_lock 的成员函数
//        //(3.1) lock()  加锁 
//        //(3.2) unlock() 解锁
//        //(3.3) try_lock() 尝试给互斥量加锁，如果拿不到锁，则返回false,如果拿到了锁，返回true, 这个函数不阻塞的；
//        // std::try_to_lock
//	//我们会尝试用mutex的lock去锁定这个mutex,但如果没有锁定成功，我们也会立即返回，并不会阻塞在那里；
//	//用这个try_to_lock的前提是你自己不能先去lock。
//        //(3.4) release()，返回它所管理的mutex对象指针，并释放所有权，也就是说，这个unique_lock和mutext不再有关系。
//        //严格区分unlock（）和release（）的区别，不要混淆。
//        //如果原来mutex对象处于加锁状态，你有责任接管过来并负责解锁。（release返回的是原始mutext）
//        //为什么有时候需要unlock（），因为你lock锁住的代码段越少，执行越快，整个程序运行效率越高。
//        //有人也把锁头锁住的代码多少 称为锁的粒度，粒度一般用粗细来描述；
//        //a）锁住的代码少，这个粒度叫细。执行效率高；
//        //b）锁住的代码多，粒度叫粗，那执行效率就低；
//        //要学会尽量选择合适粒度的代码进行保护，粒度太细，可能漏掉共享数据的保护，粒度太粗，影响效率。
//        //选择合适的粒度，是高级程序员的能力和实力的体现；
//
//int main()
//{
//    std::thread th1(task_a);
//    std::thread th2(task_b);
//
//    th1.join();
//    th2.join();
//
//    return 0;
//}
// 
// 
// 
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
