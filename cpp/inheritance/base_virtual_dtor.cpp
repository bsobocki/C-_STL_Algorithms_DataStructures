#include <iostream>

int order = 0;

struct Base {

    // constructor cannot be virtual
    Base(){
        std::cout<< order++ <<": Constructor of the Base class"<<std::endl;
    }

    virtual ~Base(){
        std::cout<< order++ <<": Virtual Destructor of the Base class" << std::endl;
    }
};

struct Derived : public Base {
    // constructor cannot be virtual
    Derived(){
        std::cout<< order++ <<": Constructor of the Derived class"<<std::endl;
    }

    ~Derived(){
        std::cout<< order++ <<": Non-Virtual Destructor of the Derived class" << std::endl;
    }
};

int main(){

    Derived* d = new Derived;  
    delete d;                   


    std::cout<<std::endl;


    Base* b = new Derived;     
    delete b;                  
}
