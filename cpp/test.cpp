// #include <iostream>
// #include <chrono>
// #include <ctime>
// using namespace std;

// int main(){
//     auto currentTime = std::time(NULL);

//     struct tm local_time;
//     localtime_r(&currentTime,&local_time);

//     uint32_t hour = (uint32_t)local_time.tm_hour;
//     uint32_t min  = (uint32_t)local_time.tm_min;
//     uint32_t sec  = (uint32_t)local_time.tm_sec;

//     return (hour * 10000) + (min * 100) + sec ;

//     return 0;
// }

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


#include <algorithm> 
#include <functional> 
#include <vector> 
#include <iostream> 
#include <boost/bind.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/ref.hpp>
#include <boost/function.hpp>
#include <cstdlib> 
#include <cstring>

// #include <boost/signal.hpp>

#include <locale>

using namespace std;

void function2();
void function3();
void function5();

// 编写一个程序，定义一个名为 button 的类，表示GUI中的一个可点击按钮。 为该类加入两个方法 add_handler() 和 remove_handler()，它们均要求一个函数名作为参数。 如果 click() 方法被调用，已登记的函数将被按顺序执行。
// 如下测试你的代码，创建一个 button 类的实例，从事件处理器内部向标准输出流写出一个信息。 调用 click() 函数模拟用鼠标点击该按钮。
// class button:public boost::signals::trackable{
// public:
//     void add_handler() const{
//         cout << "add_handler" << endl;
//     }
//     void remove_handler() const{
//         cout << "remove_handler" << endl;
//     }
// };

// void function4(){
//     boost::signal<void ()> s;
//     std::auto_ptr<button> b(new button());
//     s.connect(boost::bind(&button::add_handler,b.get()));
//     // s.connect(boost::bind(&button::remove_handler,b.get()));
//     cout << s.num_slots() << endl;
//     s();

// }
int main() 
{ 
    // function2();
    // function3();
    function5();

    
    return 0;

} 

//-------------------------------------------------------------
//字符串处理
void function5(){
    // std::locale loc;
    // cout << loc.name() << endl;

    // std::locale::global(std::locale("German")); 
    // std::locale loc; 
    // std::cout << loc.name() << std::endl; 

    std::cout << std::strcoll("ä", "z") << std::endl; 
    std::locale::global(std::locale("German")); 
    std::cout << std::strcoll("ä", "z") << std::endl;
}



// class divide_by 
//   : public std::binary_function<int, int, int> 
// { 
// public: 
//   int operator()(int n, int div) const 
//   { 
//     return n / div; 
//   } 
// }; 

void divide_by(int div,int n){
    // cout << n << "  " << div << endl;
    cout << n/div << endl;
}
void function1(){
    std::vector<int> numbers; 
    numbers.push_back(10); 
    numbers.push_back(20); 
    numbers.push_back(30); 

//   std::transform(numbers.begin(), numbers.end(), numbers.begin(), std::bind2nd(divide_by(), 2)); 
//   for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) 
//     std::cout << *it << std::endl; 


//   std::for_each(numbers.begin(),numbers.end(),boost::bind(divide_by,2,_1));
    std::for_each(numbers.begin(),numbers.end(),std::cout << boost::lambda::_1/2 << "\n");
}
//-------------------------------------------------------------------------------
void push(string s,vector<int>& size){
    size.push_back(s.size());
}

void function2(){
    std::vector<std::string> strings; 
    strings.push_back("Boost"); 
    strings.push_back("C++"); 
    strings.push_back("Libraries"); 

    std::vector<int> sizes; 

    // for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); ++it) 
    //     sizes.push_back(it->size()); 
    
    // for (std::vector<int>::iterator it = sizes.begin(); it != sizes.end(); ++it) 
    //     std::cout << *it << std::endl; 

    std::for_each(strings.begin(),strings.end(),boost::bind(push,_1,boost::ref(sizes)));
    std::for_each(sizes.begin(),sizes.end(),cout << boost::lambda::_1 << "\n");
}

void function3(){
    // std::vector<int(*)(const char*)> processors; 
    // processors.push_back(std::atoi); 
    // processors.push_back(reinterpret_cast<int(*)(const char*)>(std::strlen)); 


    const char data[] = "1.23"; 

    // for (std::vector<int(*)(const char*)>::iterator it = processors.begin(); it != processors.end(); ++it) 
    //     std::cout << (*it)(data) << std::endl; 
    
    boost::function<int (const char*)> f = std::atoi;
    cout << f(data) << endl;
    f = std::strlen;
    cout << f(data) << endl;

    
}