#include <set>
#include <vector>
#include <iostream>
#include "iterable_to_string.hpp"

int main(){
    std::vector<int> vec = {7,2,5,1,9,6,0};
    std::cout << "collection of integers: " << to_string(vec) << std::endl;

    std::set<int> set(vec.begin(), vec.end());
    std::cout << "\nsorting in O(N * log N ) time using std::set . . . \n" << std::endl;
    std::cout << "sorted collection of integers: " << to_string(set) << std::endl;
    return 0;
}