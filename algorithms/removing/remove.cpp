#include "../tools.hpp"

int main(){
    std::vector<int> nums = {1, 2, 0, 3, 0, 0, 0, 4, 5, 6, 0, 0, 7, 0, 8, 9, 0, 10};
    print("nums: ", nums);

    std::cout << "\nremoving 0 from nums . . .\n" << std::endl;
    nums.resize(
        std::distance(
            nums.begin(), 
            std::remove(nums.begin(), nums.end(), 0) // returns iterator to the end of the collection that doesn't contain 0 
        )
    );


    print("new nums: ", nums);
    return 0;
}