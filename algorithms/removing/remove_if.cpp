#include "../tools.hpp"

int main(){
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 8, 9, 10, 11, 12};
    print("nums: ", nums);

    std::cout << "\nremoving odd numbers from nums . . . \n" << std::endl;
    // returns iterator to the end of the collection that doesn't contain 0 
    auto end_iter = std::remove_if( nums.begin(), nums.end(), 
                [](const int & x) {
                    return x%2!=0;
                });

    print("nums: ", nums);

    std::cout<< "\nresizing the vector based on the returned iterator . . .\n" << std::endl;
    
    
    // std::remove_if doesn't resize vector... elements after iterator returned by this function are unchanged
    nums.resize( std::distance( nums.begin(), end_iter) );

    print("new nums: ", nums);
    return 0;
}