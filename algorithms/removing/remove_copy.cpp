#include "../tools.hpp"

int main(){
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 8, 9, 10, 11, 12};
    print("nums: ", nums);

    std::cout << "\nremoving 7 from nums and copying to a new vector. . . \n" << std::endl;
    std::vector<int> vec; 
    std::remove_copy( nums.begin(), nums.end(), std::back_inserter(vec), 7);

    print("new vector: ", vec);
    return 0;
}