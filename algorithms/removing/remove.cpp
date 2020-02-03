#include "../tools.hpp"

int main(){
    std::vector<int> nums = {1, 2, 0, 3, 0, 0, 0, 4, 5, 6, 0, 0, 7, 0, 8, 9, 0, 10};
    print("nums: ", nums);

    std::cout << "\nremoving 0 from nums . . . \n" << std::endl;
    auto end_iter = std::remove(nums.begin(), nums.end(), 0); // returns iterator to the end of the collection that doesn't contain 0
    print("nums: ", nums);
    
    std::cout << "\nresizing the vector based on the returned iterator . . .\n" << std::endl;
    
     // std::remove doesn't resize vector... elements after iterator returned by this function are unchanged
    nums.resize( std::distance( nums.begin(), end_iter ));

    print("new nums: ", nums);
    return 0;
}