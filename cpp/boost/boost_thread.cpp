#include <iostream>

#include <boost/thread.hpp>

using namespace std;

//----------------------1------------------------
void wait(int seconds)
{
    // cout << "sleep" << endl;
    boost::this_thread::sleep(boost::posix_time::seconds(seconds));
}

void thread()
{
    // for(int i = 0; i < 5 ; ++i)
    // {
    //     wait(1);
    //     cout << i << endl;
    // }
    //加上中断点
    // cout << "---add interrupt---" << endl;
    try
    {
        for(int i =0; i < 5; ++i)
        {
            wait(1);
            cout << i << endl;
        }
    }
    catch (boost::thread_interrupted&)
    {

    }
}
void thread_example1()
{
    // boost::thread t(thread);
    // t.join();
    //加上中断点
    // '''在一个线程对象上调用 interrupt() 会中断相应的线程。 在这方面，中断意味着一个类型为 boost::thread_interrupted 的异常，它会在这个线程中抛出。 然后这只有在线程达到中断点时才会发生。'''
    // '''sleep函数也是中断点'''
    // sleep() 之间的调用，却不能使线程中断
    boost::thread t2(thread);
    wait(3);
    t2.interrupt();
    t2.join();

}
//-----------------2------------------------
void thread_get_id()
{
    //返回当前线程的id号
    cout << boost::this_thread::get_id() << endl;
    //返回基于CPU数目或者CPU内核数据的同时在物理机器上运行的线程数
    //常用的双核机器上调用这个方法 返回值为2
    cout << boost::thread::hardware_concurrency() << endl;
}
//----------------3-----------------------
// 同步  使用线程在同一时间执行几个函数 访问共享资源时必须相应地同步
boost::mutex mutex;
void thread2()
{
    for(int i=0; i < 5; ++i)
    {
        wait(1);
        mutex.lock();
        cout << "Thread " << boost::this_thread::get_id() << endl;
        mutex.unlock();
    }
}
//将lock和 unlock使用 替代
// boost::lock_guard<boost::mutex> lock(mutex)
void thread2_1()
{
    for(int i=0; i < 5; ++i)
    {
        wait(1);
        boost::lock_guard<boost::mutex> lock(mutex);
        cout << "Thread_2 " << boost::this_thread::get_id() << endl;
    }
}
//使用互斥对象来同步 提供多个互斥类
//mutex全局互斥对象 标准输出流是一个全局性的被所有
void thread_mutex_example()
{
    boost::thread t1(thread2_1);
    boost::thread t2(thread2_1);
    t1.join();
    t2.join();
}
int main()
{

    thread_mutex_example();
    return 0;
}