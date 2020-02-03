#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void show(const T * const data, const int & size){
    std::cout<<" { ";
    for(unsigned int i=0; i<size-1; i++){
        std::cout<<data[i]<<", ";
    }
    std::cout<<data[size-1]<<" }\n";
}

template<class Iter>
void show(const Iter & container){
    std::cout << "{ ";
    for (auto x : container) std::cout << x << ", ";
    std::cout << "}" << std::endl;
}

template<class Iterable>
std::string to_string(Iterable it){
    std::string str = "{ ";

    for (auto x : it) 
        str += std::to_string(x) + ", "; 
    
    return str + "}";
}

template<class Iter>
void print(std::string text, Iter it){
    std::cout << text << to_string(it) << std::endl;
}

#endif //TOOLS_HPP