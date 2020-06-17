/*
 * If you have a variables, which value you want to use in lambda expression,
 * you can capture them by value, or by reference using capture list.
 * Options:
 * [] - no captured variables
 * [=] - all visible (non-static) variables by value
 * [&] - all visible (non-static) variables by reference
 * [=, x, y, z] - all visible (non-static) variables by value excluding x, y, z
 * [&, x, y, z] - all visible (non-static) variables by reference excluding x, y, z
 */

#include <iostream>
int main(){
    int a;
    int b;

    std::cout<<"---passing by value---"<<std::endl;
    std::cout<<"(get the value once and use it in each time)"<<std::endl;

    auto change_a_b = [&](int val_a, int val_b){  
        a = val_a;
        b = val_b;
        std::cout<<"\n";
        std::cout<<"a = "<<a<<"\nb = "<<b<<std::endl<<std::endl;
    };

    change_a_b(3,1);

    auto foo_a_val = [a](){ return a; };
    auto foo_b_val = [b]() -> int { return b; };

    std::cout<<"foo_a_val = "<<foo_a_val()<<std::endl;
    std::cout<<"foo_b_val = "<<foo_b_val()<<std::endl;

    change_a_b(2, 7);
    std::cout<<"foo_a_val = "<<foo_a_val()<<std::endl;
    std::cout<<"foo_b_val = "<<foo_b_val()<<std::endl;
    change_a_b(5,6);
    std::cout<<"foo_a_val = "<<foo_a_val()<<std::endl;
    std::cout<<"foo_b_val = "<<foo_b_val()<<std::endl;

    std::cout<<"\n---passing by reference---"<<std::endl;
    std::cout<<"(get the reference of the variable and in each time get the value from the reference)"<<std::endl;

    auto foo_a_ref = [&a](){ return a; };
    auto foo_b_ref = [&b]() -> int { return b; };

    change_a_b(90,100);
    std::cout<<"foo_a_ref = "<<foo_a_ref()<<std::endl;
    std::cout<<"foo_b_ref = "<<foo_b_ref()<<std::endl;

    change_a_b(2, 7);
    std::cout<<"foo_a_ref = "<<foo_a_ref()<<std::endl;
    std::cout<<"foo_b_ref = "<<foo_b_ref()<<std::endl;
    change_a_b(23,64);
    std::cout<<"foo_a_ref = "<<foo_a_ref()<<std::endl;
    std::cout<<"foo_b_ref = "<<foo_b_ref()<<std::endl;

    return 0;
}