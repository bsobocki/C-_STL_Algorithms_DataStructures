#include <iostream>
#include <memory>

class A_class{
/*  without an access specifier members are */
//  private:
        int private_member = 1;
    protected:
        int protected_member = 2;
    public:
        int public_member = 3;

        void print_members(){
            std::cout << "A_class : " << std::endl;
            std::cout << "  public_member: " << public_member << std::endl;
            std::cout << "  protected_member: " << protected_member << std::endl;
            std::cout << "  private_member: " << private_member << std::endl;
            std::cout << std::endl;
        }
};

struct A_struct{
/*  without access specifier members are */
//  public:
        int public_int = 30;
    protected:
        int protected_int = 20;
    private:
        int private_int = 10;

    
    public:
        void print_ints(){
            std::cout << "A_struct : " << std::endl;
            std::cout << "  public_int: " << public_int << std::endl;
            std::cout << "  protected_int: " << protected_int << std::endl;
            std::cout << "  private_int: " << private_int << std::endl;
            std::cout << std::endl;
        }
};


 // without a specifier it is private inheritance
 // because derived is a class, not a struct 
 // so, no one knows that B_class_A_class inherits from A_class
 // polymorphism is unavailable
class B_class_A_class: A_class { // is equilalent to class B_class_A_classs : private A_struct
/* 
In this case the private inheritance behaves like:

    private:
        int public_member;
        int protected_member;
*/
    public:
        void show_members(){
            std::cout << "B_class_A_class : " << std::endl;
            std::cout << "  public_member: " << public_member << std::endl;
            std::cout << "  protected_member: " << protected_member << std::endl;
            /* std::cout << private_member;  <------ ERROR: private_member only exists as a private member in A_class */
            /* so we have to say, that this class doesn't have private_member :( */
            std::cout << "  private_member: " << "no private_member (B_class_A_class doesn't have this field)" << std::endl;
            std::cout << std::endl;
            
            // from the class declaration you can use public and protected members in derived class declaration
            public_member;
            protected_member; 
        }
};

 // without a specifier it is private inheritance 
 // because derived is a class, not a struct 
 // so, no one knows that B_class_A_struct inherits from A_struct
 // polymorphism is unavailable
class B_class_A_struct : A_struct { // is equilalent to class B_class_A_struct : private A_struct
/* 
In this case the private inheritance behaves like:

    private:
        int public_int;
        int protected_int;
*/
    public:
        void show_members(){
            std::cout << "B_class_A_struct : " << std::endl;
            std::cout << "  public_int: " << public_int << std::endl;
            std::cout << "  protected_int: " << protected_int << std::endl;
            /* std::cout << private_int;  <------ ERROR: private_member only exists as a private member in A_class */
            std::cout << "  private_int: " << "no private_int (B_class_A_struct doesn't have this field)" << std::endl;
            std::cout << std::endl;

            // from the class declaration you can use public members from derived class
            public_int;
            protected_int; 
        }
};


 // without specifier it is public inheritance
 // because derived is a struct, not a struct 
 // so, everyone knows that B_class_A_struct inherits from A_class
 // polymorphism is available
struct B_struct_A_class : A_class{ // is equivalent to struct B_struct_A_class : public A_class
/*
In this case the public inheritance behaves like:

    public:
        int public_member;
    protected:
        int protected_member;
*/
};


 // without specifier it is public inheritance
 // because derived is a struct, not a struct 
 // so, everyone knows that B_class_A_struct inherits from A_class
 // polymorphism is available
struct B_struct_A_struct : A_struct{ // is equivalent to struct B_struct_A_struct : public A_struct
/*
In this case the public inheritance behaves like:

    public:
        int public_int;
    protected:
        int protected_int;
*/
};


// we have protected inheritance
 // polymorphism is unavailable
class protected_derived : protected A_class {
/*
In this case the public inheritance behaves like:

    public:
        int public_int;
    protected:
        int protected_int;

*/
    public:
        void foo(){
            /*
                private_member;   <---- ERROR
            */
           protected_member; // OK !
           public_member; // OK !
        }
};

int main(){

    auto A_class_u_ptr = std::make_unique<A_class>();
    A_class_u_ptr -> public_member; // OK !
    A_class_u_ptr -> print_members(); // OK !

    auto A_struct_u_ptr = std::make_unique<A_struct>();
    A_struct_u_ptr -> public_int; // OK !
    A_struct_u_ptr -> print_ints(); // OK !

    std::cout << " ----------------- " << std::endl << std::endl;


    auto B_class_A_class_u_ptr = std::make_unique<B_class_A_class>();
    /* 
        B_class_A_class_u_ptr -> public_member;   <----- ERROR 
        B_class_A_class_u_ptr -> print_members(); <----- ERROR
    */
    B_class_A_class_u_ptr -> show_members();


    std::cout << " ----------------- " << std::endl << std::endl;


    auto B_class_A_struct_u_ptr = std::make_unique<B_class_A_struct>();
    /* 
        B_class_A_struct_u_ptr -> public_int;   <----- ERROR 
        B_class_A_struct_u_ptr -> print_members(); <----- ERROR
    */
    B_class_A_struct_u_ptr -> show_members();


    std::cout << " ----------------- " << std::endl << std::endl;


    auto B_struct_A_class_u_ptr = std::make_unique<B_struct_A_class>();
    std::cout << "Derived Struct:" << std::endl;
    B_struct_A_class_u_ptr -> print_members();
    std::cout << "Access to public_member from B_struct_A_class in function main(): " << B_struct_A_class_u_ptr -> public_member << std::endl;


    std::cout << " ----------------- " << std::endl << std::endl;


    auto B_struct_A_struct_u_ptr = std::make_unique<B_struct_A_struct>();
    std::cout << "Derived Struct:" << std::endl;
    B_struct_A_struct_u_ptr -> print_ints();
    std::cout << "Access to public_int from B_struct_A_struct in function main(): " << B_struct_A_struct_u_ptr -> public_int << std::endl;


    std::cout << "\n\nConclusion:\n"
                 " Whether inheritance is private or public depends on the derivative.\n"
                 " If it is struct - public inheritance\n"
                 " If it is class - private inheritance" << std::endl;


    /*
    
    A_class* a = new B_class_A_class();  // ERROR ! private inheritance ! the base  class is unavailable !
    A_class* s = new B_struct_A_class(); // OK !

    A_struct* d = new B_class_A_struct(); // ERROR ! private inheritance ! the base  class is unavailable !
    A_struct* e = new B_struct_A_struct(); // OK !
    
    A_class* ac = new protected_derived(); // ERROR ! protected inheritance ! the base  class is unavailable !
    
    */
    return 0;
}