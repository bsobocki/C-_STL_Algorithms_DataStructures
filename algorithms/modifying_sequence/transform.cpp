#include <algorithm>
#include <iostream>
#include <vector>
#include "../tools.hpp"

int main() {
    std::vector<unsigned int> vec = {3, 4, 10, 11, 12, 42, 43, 56, 732, 578, 21, 453, 5, 7, 2, 4, 7, 4, 2};
    std::cout << "vec = " << to_string(vec) << std::endl;
    
    std::vector<unsigned int> res;

    std::transform(vec.begin(), vec.end(), std::back_inserter(res), 
        [] (const unsigned int & x) { 
            if ( x < 10 ) 
                return x+30; 
            return x%10 + 30; 
        });

    std::cout<< "\nresult of transform contains only values bigger or equal to 30: " << to_string(res) << std::endl;

    std::transform(res.begin(), res.end(), vec.begin(), 
        [] (const unsigned int & x) {
            return x%10;
        });
    std::cout << "\nThe next transform change vec to vector = " << to_string(vec) << std::endl;

    std::transform(vec.begin(), vec.end(), vec.begin(), 
        [] (const unsigned int & x) {
            return x*x;
        });
    std::cout << "\nAnd the last transform... now vec contains only squares of its own elements: " << to_string(vec) << std::endl;
    return 0;
}