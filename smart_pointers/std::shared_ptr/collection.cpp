#include <iostream>

class A {
 public:
    virtual void write(){
        std::cout<<"I'm A virtual method!"<<std::endl;
    }
};

class B: public A {
 public: 
    void write(){
        std::cout<<"I'm B virtual method!"<<std::endl;
    }
    void write(B & a){
        a.write();
    }
};

class C: public B {
public:
    void write(){
        std::cout<<"I'm C virtual method!"<<std::endl;
    }

    void write(A & a){
        a.write();
    }
};

class D: public A {
public:
    void write(){
        std::cout<<"I'm D virtual method!"<<std::endl;
    }
};

int main(){
    A a;
    B b;
    C c;
    D d;

    a.write();
    b.write();
    c.write();
    d.write();
    std::cout<<"----"<<std::endl;
    b.write( static_cast<B&>(c) );
    c.write(b);

    return 0;
}