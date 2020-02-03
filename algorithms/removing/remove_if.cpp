#include "../tools.hpp"

int main(){
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print("nums: ", nums);

    std::cout << "\nremoving odd numbers from nums and resizing the vector based on the returned iterator . . .\n" << std::endl;
    nums.resize( // std::remove_if doesn't resize vector... elements after iterator returned by this function are unchanged
        std::distance(
            nums.begin(), 
            std::remove_if(// returns iterator to the end of the collection that doesn't contain 0 
                nums.begin(), 
                nums.end(), 
                [](const int & x) {
                    return x%2!=0;
                }
            ) 
        )
    );

    print("new nums: ", nums);
    return 0;
}