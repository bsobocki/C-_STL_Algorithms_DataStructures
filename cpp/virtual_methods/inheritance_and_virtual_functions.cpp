#include <iostream>

struct A {
public: 
    // It's a virtual member function 
    // so the derived class will be able 
    // to say their words while using polymorphism
    virtual void say_hello() const{
        std::cout<<"- Hi! I'm Struct A! Welcome in my world!"<<std::endl;
    }

    // It's not a virtual member function
    // so if we use polymirphism -  B as A
    // it will call this method, so it will print "- HAHA, Only A can speak!"
    void say_something() const {
        std::cout<< "- HAHA, Only A can speak!"<<std::endl;
    }
};


class B : public A {
public: 
    virtual void say_hello() const{
        std::cout<<"- Hi! I'm Object B! Nice to meet you!"<<std::endl;
    }

    virtual void say_something() const{
        std::cout<<"- B can also speak!"<<std::endl;
    }
};


class C : public B {
public: 
    void say_hello() const{
        std::cout<<"- Hi everyone! I'm a little object C, my parent is B and I'm so proud of it."<<std::endl;
    }

    void say_something() const{
        std::cout<<"- C can also speak!"<<std::endl;
    }

    // derived classes will not be able to speak slowly
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
        std::cout<<"- D can also speak!"<<std::endl;
    }

    void speak_slowly() const{
        std::cout<<"- I'-m - D - a-n-d - I - c-a-n - s-p-e-a-k - s-l-o-w-l-y...!"<<std::endl;
    }
};


void intro(const A & obj){
    obj.say_hello();
}

void speak(const A & obj){
    obj.say_something();
}

void speak_slowly(const C& obj){
    obj.speak_slowly();
}

void speak_as_b(const B& obj){
    obj.say_something();
}


int main(){
    B b;
    C c;
    D d;
    
    std::cout<< "- Hello letters! Now You are speaking as object of the 'A' class!\n" <<std::endl;
    
    std::cout << "\n- Hey C! Could you say hello ? Your member function 'say_hello' is not virtual!" << std::endl;
    intro(c);

    std::cout << "\n- And now B! Could you say hello? Your  member function 'say_hello' is virtual!" << std::endl;
    intro(b);

    std::cout<< "\n- Say something C! The 'say_something' method of your parent A is not virtual... It will be possible to use C::say_something() ?"<<std::endl;
    speak(c);

    std::cout<< "\n- Say something B! The 'say_something' method of your parent A is not virtual, but yours is... It will be possible to use B::say_something() ?"<<std::endl;
    speak(b);
    
    std::cout<< "\n- Say something D! The 'say_something' method of your parent A is not virtual, but yours too... May It will be possible to use D::say_something() ?"<<std::endl;
    speak(d);

    std::cout<<"\n- It's so sad :(\n"<<std::endl;
    
    std::cout<< "- D! Now You are speaking as object of the 'C' class!" <<std::endl;
    
    std::cout<< "\n- You are class that parent is C! We know that C can speak slowly... Can you speak slowly?"<<std::endl;
    speak_slowly(d);

    std::cout<< "\n- Okay.. But Letters.. Can you say something without use polymorphism?"<<std::endl;
    b.say_something();
    c.say_something();
    d.say_something();

    std::cout<< "\n- Say something C as B!"<<std::endl;
    speak_as_b(c);

    std::cout<< "\n- Say something D as B!"<<std::endl;
    speak_as_b(d);


    return 0;
}
