#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iostream>
#include <vector>

void show(const int * const data, const int & size){
    std::cout<<" { ";
    for(unsigned int i=0; i<size-1; i++){
        std::cout<<data[i]<<", ";
    }
    std::cout<<data[size-1]<<" }\n";
}

template<class T>
void show(const T & container){
    show(container.data(), container.size());
}

template<class Iterable>
std::string to_string(Iterable it){
    std::string str = "{ ";

    for (auto x : it) 
        str += std::to_string(x) + ", "; 
    
    return str + "}";
}

#endif //TOOLS_HPP