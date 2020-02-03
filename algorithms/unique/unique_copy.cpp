#include "../tools.hpp"

int main(){
    std::vector<int> nums =  {1,1,1, 2,2,2, 3,3,3 ,4,4,4, 5,5,5, 4,4,4, 5,5,5, 6,6, 7};
    std::vector<int> new_nums;
    print("nums: ", nums);
    print("new_nums: ", new_nums);

    std::cout << "\ncopying unique values from nums to new_nums . . . \n" << std::endl;
    std::unique_copy(nums.begin(), nums.end(), std::back_inserter(new_nums));
    print("new_nums: ", new_nums);

    return 0;
}