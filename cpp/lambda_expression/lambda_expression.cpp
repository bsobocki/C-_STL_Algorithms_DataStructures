/*
 * lambda expression is available since c++11
 * construction:
 * [] --- capture list
 * () --- parameter list
 * mutable (optional)
 * exception specification (optionally)
 * -> type --- return type (optionally)
 * {} -- function body
 */

#include <iostream>

int main(){

    int a = 9;
    int b = 3;
    
    // 1 - specify return type 
    auto lamb1 = [](int a, int b) -> int { return a + b; };

    // 2 - the same function without return type specification
    auto lamb2 = [](int a, int b) {return a + b; };

    // 3 - capture a by reference and b by value
    auto lamb3 = [&a, b]() { return a + b; };

    // 4 - capture a by reference other variables by value
    auto lamb4 = [=, &a]() { return a + b; };

    // 5 - capture b by value and other variables by reference
    auto lamb5 = [&, b]() { return a + b; };

    // 6 - delare that the function doesn't throw exception
    auto lamb6 = [](int a) noexcept { return a; };

    // 7 - noexcept and return type - int
    auto lamb7 = [](int a, int b) noexcept -> int { return a + b; };

    // 8 - capture all local variables by value
    auto lamb8 = [=](){ return a + b; };

    // 9 - capture all local variables by reference 
    auto lamb9 = [&](){ return a + b; };

    return 0;
}