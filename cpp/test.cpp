#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

int main(){
    auto currentTime = std::time(NULL);

    struct tm local_time;
    localtime_r(&currentTime,&local_time);

    uint32_t hour = (uint32_t)local_time.tm_hour;
    uint32_t min  = (uint32_t)local_time.tm_min;
    uint32_t sec  = (uint32_t)local_time.tm_sec;

    return (hour * 10000) + (min * 100) + sec ;

    return 0;
}

// class Trace{

// public:
//     Trace(){
//         noisy = 0;
//         f = stdout;
//     }
//     Trace(FILE* ff){
//         f = ff;
//     }
//     void print(char* s){
//         if(noisy){
//             f << s << endl;
//         }
//     }
//     void on(){
//         noisy = 1;
//     }
//     void off(){
//         noisy = 0;
//     }

// private:
//     int noisy;
//     FILE* f;
// };