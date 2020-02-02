#include <set>
#include <iostream>
#include <vector>
#include "iterable_to_string.hpp"

int main(){
    std::vector<int> vec = {0, 0, 0, 0, 1, 1, 2, 3, 1, 4, 0, 4, 2, 6, 3, 56, 7}; // uniques: 0,1,2,3,4,6,7,56
    std::cout << "collection = " << to_string(vec) << std::endl;

    std::set<int> set(vec.begin(), vec.end());
    std::cout << "unique values from collection in O(N log N) time <-- insert operation is O(log N) = " << to_string(set) << std::endl;

    return 0;
}