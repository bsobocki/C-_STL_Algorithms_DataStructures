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

    virtual ~Derived(){
        std::cout<< order++ <<": Virtual Destructor of the Derived class" << std::endl;
    }
};

int main(){

    Derived* d = new Derived;   // first -> "Constructor of the Base class"
                                // next  -> "Constructor of the Derived class"
    
    delete d;                   // first: -> "Virtual Destructor of the Derived class"
                                // next:  -> "Virtual Destructor of the Base class"

    std::cout<<std::endl;

    Base* b = new Derived;      // first -> "Constructor of the Base class"
                                // next  -> "Constructor of the Derived class"

    
    delete b;                   // first: -> "Virtual Destructor of the Derived class"
                                // next:  -> "Virtual Destructor of the Base class"

    std::cout<<std::endl;

/*
    Derived* c = new Base;      // ERROR: cannot initialize Derived by Base
*/

}