#include <iostream>
#include <pthread.h>
#include <mutex>
#include <cstdlib>
using namespace std;

//加锁的懒汉模式 线程安全
//和不加锁的模式对比：

// 增加成员变量mutex
// getInstance和deleteInstance增加锁
// getInstance 使用双检锁
// getInstance 返回值 * &


class SingleInstance{

public:
    //* &
    static SingleInstance* getInstance();
    static void deleteInstance();
    void Print();    

private:
    SingleInstance();
    ~SingleInstance();

    SingleInstance(const SingleInstance& signal);
    const SingleInstance &operator=(const SingleInstance& signal);

private:
    static SingleInstance* m_SingleInstance;

    //mutex
    static std::mutex m_Mutex;

};
//初始化静态成员变量
SingleInstance* SingleInstance::m_SingleInstance = NULL;
//初始化mutex
std::mutex SingleInstance::m_Mutex;

SingleInstance::SingleInstance(){
    cout << "构造函数" << endl;
}
SingleInstance::~SingleInstance(){
    cout << "析构函数" << endl;
}
void SingleInstance::deleteInstance(){
    //加锁
    std::unique_lock<std::mutex> lock(m_Mutex);
    if(m_SingleInstance){
        delete m_SingleInstance;
        m_SingleInstance = NULL;
    }
}
SingleInstance* SingleInstance::getInstance(){
    //此处的if为双检锁 只有指针为空的时候才加锁
    //避免每次调用getInstance 方法时都加锁 （锁的开销较大）
    if(m_SingleInstance == NULL){
        //加锁
        std::unique_lock<std::mutex> lock(m_Mutex);
        if(m_SingleInstance == NULL)
            m_SingleInstance = new(std::nothrow) SingleInstance;
    }
    return m_SingleInstance;
}
void SingleInstance::Print(){
    cout << "Address = " << this << endl;
}

void* PrintHello(void* threadid){
    //主线程与子线程分离
    pthread_detach(pthread_self());

    int tid = *((int *)threadid);

    cout << "threadid = [" << tid << "]" << endl;

    SingleInstance::getInstance()->Print();

    pthread_exit(NULL); 
}

#define NUM_THREADS 5

int main(void){

    pthread_t threads[NUM_THREADS] ={0};
    int indexes[NUM_THREADS] ={0};

    int ret = 0;
    int i = 0;
    
    cout << "...main()..." << endl;

    for (i=0; i< NUM_THREADS ; i++){
        cout << "...create..threads[" << i << "]"  << endl;
        indexes[i] = i;//保存i的值到数组中

        ret = pthread_create(&threads[i],NULL,PrintHello,(void*)&(indexes[i]));
        if(ret){
            cout << "Can't create thread " << ret << endl;
            exit(-1);
        } 
        
    }
    //手动释放单实例的资源
    SingleInstance::deleteInstance();
    cout << "main() finished" << endl;
    return 0;
}

//内部静态变量的懒汉模式 代码量少 
//内部没有静态成员变量
class Single{

public:
    static Single& getInstance();

private:
    Single();
    ~Single();
    Single(const Single& signal);
    cosnt Single& operator=(cosnt Single&signal);
}

Single& Single::getInstance(){
    static Single m_single;
    return m_single;
}
Single::Single()
{
    std::cout << "构造函数" << std::endl;
}

Single::~Single()
{
    std::cout << "析构函数" << std::endl;
}