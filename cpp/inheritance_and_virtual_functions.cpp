#include <iostream>

struct A {
public: 
    // It's a vitrual member function
    // so the derivated class will be able to say their words
    // while using polymorphism
    virtual void say_hello() const{
        std::cout<<"- Hi! I'm Struct A! Welcome in my world!"<<std::endl;
    }

    void say_something() const {
        std::cout<< "- HAHA, Only A can talk!"<<std::endl;
    }
};

class B : public A {
public: 
    virtual void say_hello() const{
        std::cout<<"- Hi! I'm Object B! Nice to meet you!"<<std::endl;
    }

    virtual void say_something() const{
        std::cout<<"- B can also talk!"<<std::endl;
    }
};

class C : public B {
public: 
    void say_hello() const{
        std::cout<<"- Hi everyone! I'm a little object C, my parent is B and I'm so proud of it."<<std::endl;
    }

    void say_something() const{
        std::cout<<"- C can also talk!"<<std::endl;
    }

    // derivative classes will not be able to speak slowly
    // while using polymorphism
    void speak_slowly() const{
        std::cout<<"- O-n-l-y - C - c-l-a-s-s - c-a-n - d-o - i-t - w-h-i-l-e - u-s-i-n-g - p-o-l-y-m-o-r-p-h-i-s-m...!"<<std::endl;
    }
};

class D : public C {
public: 
    virtual void say_hello() const{
        std::cout<<"- Hi! I'm a big class D! How are you?"<<std::endl;
    }

    void say_something() const{
        std::cout<<"- D can also talk!"<<std::endl;
    }

    void speak_slowly() const{
        std::cout<<"- I'-m - D - a-n-d - I - c-a-n - s-p-e-a-k - s-l-o-w-l-y...!"<<std::endl;
    }
};

void intro(const A & obj){
    obj.say_hello();
}

void talk(const A & obj){
    obj.say_something();
}

void speak_slowly(const C& obj){
    obj.speak_slowly();
}

int main(){
    B b;
    C c;
    D d;

    std::cout << "\n- Hey C! Could you say hello ? Your member function 'say_hello' is not virtual!" << std::endl;
    intro(c);

    std::cout << "\n- And now B! Could you say hello? Your  member function 'say_hello' is virtual!" << std::endl;
    intro(b);

    std::cout<< "\n- Say something C! The 'say_something' method of your parent A is not virtual... It will be possible to use C::say_something() ?"<<std::endl;
    talk(c);

    std::cout<< "\n- Say something B! The 'say_something' method of your parent A is not virtual, but yours is... It will be possible to use B::say_something() ?"<<std::endl;
    talk(b);
    
    std::cout<< "\n- Say something D! The 'say_something' method of your parent A is not virtual, but yours too... May It will be possible to use D::say_something() ?"<<std::endl;
    talk(d);

    std::cout<<"\n- It's so sad :("<<std::endl;
    
    std::cout<< "\n- D! You are class that parent is C! We know that C can speak slowly... Can you speak slowly?"<<std::endl;
    speak_slowly(d);
    return 0;
}