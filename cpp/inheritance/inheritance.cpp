#include <iostream>

int order = 0;

struct Base {
    Base(){
        std::cout<< order++ <<": Constructor of the Base class"<<std::endl;
    }

    ~Base(){
        std::cout<< order++ <<": Destructor of the Base class" << std::endl;
    }
};

struct Derived : public Base {
    Derived(){
        std::cout<< order++ <<": Constructor of the Derived class"<<std::endl;
    }

    ~Derived(){
        std::cout<< order++ <<": Destructor of the Derived class" << std::endl;
    }
};

int main(){

    Derived* d = new Derived;   // first -> "Constructor of the Base class"
                                // next  -> "Constructor of the Derived class"

    return 0;
}