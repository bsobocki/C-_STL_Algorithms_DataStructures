#include <iostream>

class A {
    public:
    // static class field
    static int A_objects_counter ;
    // static class function
    static void reset_A_counter() { A_objects_counter = 0; }
    static int get_A_object_counter() { return A_objects_counter; }
    
    protected:
        // object member fields
        int a,b;

    public:
        A(int aa, int bb): a(aa), b(bb) { A_objects_counter ++; }
};

class B : public A {
    public:
    // static class field
    static int B_objects_counter;
    static int get_B_object_counter() { return B_objects_counter; }
    static void reset_B_counter() { B_objects_counter = 0; }

    public:
        B(int aa, int bb): A(a,b) { B_objects_counter ++; }

};

// you have to initialize static fields
// outside main function 
int A::A_objects_counter = 0;
int B::B_objects_counter = 0;

int main () {

    // 6 A objects including 2 B objects
    A a1(0,1);
    B b1(1,2);
    A a2(2,3);
    B b2(3,4);
    A a3(4,5);
    A a4(5,6);   

    std::cout << "There are " << A::A_objects_counter<< " objects with type A including " << B::B_objects_counter << " objects with type B" << std::endl;

    
    // attempt to call reset_counter from derived class; 
    B::reset_A_counter();  // number of A objects == 0

    // 3 A objects including 3 B objects
    B b3(3,4);
    B b4(4,5);
    B b5(5,6);   

    // so we have 9 A objects including 5 B objects
    // but the output will be diggerent... :P
    std::cout << "There are " << A::A_objects_counter<< " objects with type A including " << B::B_objects_counter << " objects with type B" << std::endl;
    
    B::reset_B_counter();
    std::cout << "Now there are " << A::A_objects_counter<< " objects with type A including " << B::B_objects_counter << " objects with type B" << std::endl;
    return 0;
}