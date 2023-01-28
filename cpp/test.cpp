#include <iostream>
using namespace std;

class Trace{

public:
    Trace(){
        noisy = 0;
        f = stdout;
    }
    Trace(FILE* ff){
        f = ff;
    }
    void print(char* s){
        if(noisy){
            f << s << endl;
        }
    }
    void on(){
        noisy = 1;
    }
    void off(){
        noisy = 0;
    }

private:
    int noisy;
    FILE* f;
};