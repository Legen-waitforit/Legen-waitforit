#include <iostream>
#include <mutex>
#include <pthread.h>
#include <cstdlib>

using namespace std;

class Singleton{

public:
    static Singleton* getInstance();
    static void deleteInstance();

    void Print();

private:
    Singleton();
    ~Singleton();

    //拷贝 & 赋值
    Singleton(const Singleton& signal);
    const Singleton& operator=(const Singleton& signal);

private:
    static Singleton* m_SingleInstance;
};

Singleton* Singleton::m_SingleInstance = new(nothrow) Singleton;
Singleton* Singleton::getInstance(){
    return m_SingleInstance;
}
void Singleton::deleteInstance(){
    if(m_SingleInstance){
        delete m_SingleInstance;
        m_SingleInstance = NULL;
    }
}
void Singleton::Print(){
    cout << "thread address" << this << endl;
}
Singleton::Singleton(){

}
Singleton::~Singleton(){

}

void* PrintHello(void* threadid){

    pthread_detach(pthread_self());

    int tid = *((int *)threadid);
    cout << "thread  id = [" << tid << "]" << endl;

    Singleton::getInstance()->Print();

    pthread_exit(NULL);
}

#define NUM_THREADS 5
int main(){

    cout << "..main().." << endl;
    
    pthread_t threads[NUM_THREADS] = {0};
    int indexes[NUM_THREADS] = {0};

    int ret = 0;
    int i = 0;

    for (i=0;i<NUM_THREADS;i++){

        cout << "create_thread["<<i << "]" << endl;
        indexes[i] = i;

        int ret = pthread_create(&threads[i],NULL,PrintHello,(void*)&indexes[i]);
        if (ret){
            cout << "create_thread_error ret = " << ret  << endl;
            exit(-1);
        }
    }
    
    Singleton::deleteInstance();
    
    cout << "..all_finished.." << endl;

    return 0;
}