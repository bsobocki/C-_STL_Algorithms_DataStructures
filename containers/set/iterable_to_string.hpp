#include <iostream>

template<class Iterable>
std::string to_string(Iterable it){
    std::string str = "{ ";

    for (auto x : it) 
        str += std::to_string(x) + ", "; 
    
    return str + "}";
}