#include <iostream>

int order = 0;

struct Base {

    // constructor cannot be virtual
    Base(){
        std::cout<< order++ <<": Constructor of the Base class"<<std::endl;
    }

    ~Base(){
        std::cout<< order++ <<": Non-Virtual Destructor of the Base class" << std::endl;
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

struct Child : Derived {
    // constructor cannot be virtual
    Child(){
        std::cout<< order++ <<": Constructor of the Child class"<<std::endl;
    }

    ~Child(){
        std::cout<< order++ <<": Non-Virtual Destructor of the Child class" << std::endl;
    }
};

int main(){

    std::cout<<"\n-----------------------------------\n"<<std::endl;

    std::cout<<"-----Child* c = new Child;-----"<<std::endl;
    Child* c = new Child;   

    std::cout<<"\n-----c->~Base();-----"<<std::endl;
    c->~Base();                 

    std::cout<<"\n-----c->~Derived();-----"<<std::endl;
    c->~Derived();            

    std::cout<<"\n-----c->~Child();-----"<<std::endl;
    c->~Child();            

    std::cout<<"\n-----delete c;-----"<<std::endl;
    delete c;      


    std::cout<<"\n-----------------------------------\n"<<std::endl;


    std::cout<<"\n-----Child* c1 = new Child;-----"<<std::endl;
    Child* c1 = new Child;    

    std::cout<<"\n-----c1->~Derived();-----"<<std::endl;
    c1->~Derived();            

    std::cout<<"\n-----c1->~Child();-----"<<std::endl;
    c1->~Child();            

    std::cout<<"\n-----delete c;-----"<<std::endl;
    delete c1;                  


    std::cout<<"\n-----------------------------------\n"<<std::endl;


    std::cout<<"\n-----Child* c2 = new Child;-----"<<std::endl;
    Child* c2 = new Child;

    std::cout<<"\n-----delete c2;-----"<<std::endl;
    delete c2;


    std::cout<<"\n-----------------------------------\n"<<std::endl;


    std::cout<<"\n-----Derived* d = new Derived;-----"<<std::endl;
    Derived* d = new Derived;   

    std::cout<<"\n-----d->~Base();-----"<<std::endl;
    d->~Base();                 

    std::cout<<"\n-----d->~Derived();-----"<<std::endl;
    d->~Derived();            

    std::cout<<"\n-----delete d;-----"<<std::endl;
    delete d;                  


    std::cout<<"\n-----------------------------------\n"<<std::endl;


    std::cout<<"\n-----Derived* d1 = new Derived;-----"<<std::endl;
    Derived* d1 = new Derived;   

    std::cout<<"\n-----d1->~Derived();-----"<<std::endl;
    d1->~Derived();              

    std::cout<<"\n-----delete d1;-----"<<std::endl;
    delete d1;                   


    std::cout<<"\n-----------------------------------\n"<<std::endl;


    std::cout<<"\n-----Derived* d2 = new Derived;-----"<<std::endl;
    Derived* d2 = new Derived;   

    std::cout<<"\n-----delete d2;-----"<<std::endl;
    delete d2;                 


    std::cout<<"\n-----------------------------------\n"<<std::endl;


    std::cout<<"\n-----Derived* der_child = new Child;-----"<<std::endl;
    Derived* der_child = new Child;  
     
    std::cout<<"\n-----der_child->~Base();-----"<<std::endl;
    der_child->~Base();    

    std::cout<<"\n-----der_child->~Derived();-----"<<std::endl;
    der_child->~Derived();    

    std::cout<<"\n-----delete der_child;-----"<<std::endl;
    delete der_child;   


    std::cout<<"\n-----------------------------------\n"<<std::endl;


    std::cout<<"\n-----Base* b = new Derived;-----"<<std::endl;
    Base* b = new Derived;     

    std::cout<<"\n-----b->~Base();-----"<<std::endl;
    b->~Base();                

    std::cout<<"\n-----delete b;-----"<<std::endl;
    delete b;                 

    std::cout<<"\n-----------------------------------\n"<<std::endl;


    std::cout<<"\n-----Base* b1 = new Derived;-----"<<std::endl;
    Base* b1 = new Derived;     

    std::cout<<"\n-----delete b1;-----"<<std::endl;
    delete b;                   

    std::cout<<"\n-----------------------------------\n"<<std::endl;


    std::cout<<"\n-----Base* base = new Base;-----"<<std::endl;
    Base* base = new Base;  
     
    std::cout<<"\n-----base->~Base();-----"<<std::endl;
    base->~Base();    

    std::cout<<"\n-----delete base;-----"<<std::endl;
    delete base;   

    std::cout<<"\n-----------------------------------\n"<<std::endl;


    std::cout<<"\n-----Base* base_child = new Child;-----"<<std::endl;
    Base* base_child = new Base;  
     
    std::cout<<"\n-----base_child->~Base();-----"<<std::endl;
    base_child->~Base();    

    std::cout<<"\n-----delete base_child;-----"<<std::endl;
    delete base_child;   
}