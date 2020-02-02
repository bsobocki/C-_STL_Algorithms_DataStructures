#include <iostream>

void foo(){
    // this initialization will be occur only once
    // every next calling 'foo' will have 'counter' initialized 
    // by the value of the 'counter' after previous calling 'foo'
    static int counter = 0;

    std::cout << "foo has been called " << ++counter << " times. " << std::endl;
}

int main() {
    foo();
    foo();
    foo();
    foo();

    return 0;
}