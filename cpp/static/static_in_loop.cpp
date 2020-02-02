#include <iostream>

int main () {

    int temp; // not initialized

    for(int i = 0; i < 10 ; i++)
        for(int j = 0 ; j < 30 ; j++){
            // static variable 'count' live in loop
            static int count = 1;   // it will be assign only once because of 'static' keyword 
            temp = count ++;
        }
    
    //std::cout << "count = " << count;  <---- ERROR: 'count' is not defined 
    std::cout << "count = " << temp <<std::endl;

    return 0;
}