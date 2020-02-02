#include <unordered_set>
#include <vector>
#include "iterable_to_string.hpp"

int main(){
    std::vector<int> vec = {6,3,7,2,7,3,6,8,9,2,5,3,7,8,2,1,7,8,33,4,5,7};
    std::cout << "collection = " << to_string(vec) << std::endl;

    std::unordered_set<int> u_set(vec.begin(), vec.end());
    std::cout << "uniques in O(N) <-- insert operation is O(1) = " << to_string(u_set) << std::endl;

    return 0;
}