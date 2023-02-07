// #include <boost/signal.hpp> 
// #include <iostream> 

// void func() 
// { 
//   std::cout << "Hello, world!" << std::endl; 
// } 

// int main() 
// { 
//   boost::signal<void ()> s; 
//   boost::signals::connection c = s.connect(func); 
//   s(); 
//   c.disconnect(); 
// } 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp> 
using namespace std;

struct Test{
  int a;
  int b;
  int c;
};

int main(){

  vector<string> vec;
  vec.push_back("1");
  vec.push_back("2");
  vec.push_back("3");
  vec.push_back("4");

  // memset(&t,0,sizeof(t));
  
  // vec.push_back(t);
  // t.a = 1;
  // t.b = 4;
  // t.c = 5;
  // vec.push_back(t);
  // t.a = 2;
  // t.b = 4;
  // t.c = 5;
  // vec.push_back(t);

  // vector<Test>::iterator it = vec.begin();
  // // cout << std::count(vec.begin(),vec.end(),it->a==1) << endl;
  // bool is_zero = true;
  // for(; it!=vec.end();it++){
  //   if(it->a == 1)
  //     cout << it->a << " " << it->b << "  " << it->c << endl;
  //     is_zero = false;
  // }

  // string s = "11 22 33 44";
  // std::cout << boost::algorithm::contains(s, "11 22 33") << std::endl; 
  cout << boost::algorithm::join(vec," ") << endl;

  return 0;
}