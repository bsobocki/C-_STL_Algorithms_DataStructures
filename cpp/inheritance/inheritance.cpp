#include <iostream>

int order = 0;

struct Base {
    Base(){
        std::cout<< order++ <<": Constructor of the Base class"<<std::endl;
    }
};

struct Derived : public Base {
    Derived(){
        std::cout<< order++ <<": The Derived Constructor"<<std::endl;
    }
};

int main(){

    Derived* d = new Derived;   // first -> "Constructor of the Base Class"
                                // next  -> "The Derived Constructor"

    return 0;
}