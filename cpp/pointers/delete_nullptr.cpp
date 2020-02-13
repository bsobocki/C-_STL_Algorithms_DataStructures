#include <iostream>

int main(){
    int* pointer = nullptr;
    delete pointer; // everything is okay; exit code: 0
}