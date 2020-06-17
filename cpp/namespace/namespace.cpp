#include <iostream>

namespace As{

class A{
    public:
        A();
        ~A();

    public:
        static A give_me_A();
};

}

As::A::A() {
    std::cout<<"ctor"<<std::endl; 
    this->~A();
    std::cout<<"----------"<<std::endl;
}

As::A::~A() {
    std::cout<<"dtor"<<std::endl;
}

As::A As::A::give_me_A() {
    return A(); 
}

int main(){
    As::A a;
    As::A b = As::A::give_me_A();
    return 0;
}