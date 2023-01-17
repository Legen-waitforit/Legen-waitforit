// 单例 
//普通懒汉模式 线程不安全
#include <iostream>
#include <mutex>
#include <pthread.h>
#include <cstdlib>

using namespace std;

class SingleInstance
{
public:
    //getInstance获取单例对象 返回单例对象
    static SingleInstance*  getInstance();

    //释放单例，进程退出时调用
    static void deleteInstance();

    //打印单例地址
    void Print();

private:
    //私有的构造函数和析构函数 禁止外部构造和析构
    SingleInstance();
    ~SingleInstance();

    //拷贝构造函数
    SingleInstance(const SingleInstance &signal);
    //赋值构造函数
    const SingleInstance &operator=(const SingleInstance &signal);

private:
    //唯一单例对象指针
    static SingleInstance* m_SingleInstance;
};
//在类外面初始化静态成员变量
SingleInstance* SingleInstance::m_SingleInstance = NULL;

SingleInstance* SingleInstance::getInstance(){
    if(m_SingleInstance == NULL){
        //没有加锁是线程不安全的 线程并发时会创建多个实例
        m_SingleInstance = new(std::nothrow) SingleInstance;
    }
    return m_SingleInstance;
}
void SingleInstance::deleteInstance(){
    if(m_SingleInstance){
        delete m_SingleInstance;
        m_SingleInstance = NULL;
    }
}
void SingleInstance::Print(){
    cout << "实例内存地址为 ： " << this << endl;
}
SingleInstance::SingleInstance(){
    cout << "构造函数" << endl;
}
SingleInstance::~SingleInstance(){
    cout << "析构函数" << endl;
}


void* PrintHello(void* threadid){
    //主线程与子线程分离 两者互不干涉，子线程结束时子线程的资源自动回收
    pthread_detach(pthread_self());

    //对传入的参数进行强制类型转换 由无类型指针变为整数指针 然后再读取
    int tid = *((int *)threadid);//最外面是解引用

    cout << "threadID = " << tid << endl;

    SingleInstance::getInstance()->Print();

    pthread_exit(NULL);
}

#define NUM_THREADS 2
int main(void){

    pthread_t threads[NUM_THREADS] ={0};
    int indexes[NUM_THREADS] ={0};

    int ret = 0;
    int i = 0;
    
    cout << "...main()..." << endl;

    for (int i=0; i< NUM_THREADS ; i++){
        cout << "main()...create..threads[" << i << "]"  << endl;
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


//饿汉模式 多线程安全
