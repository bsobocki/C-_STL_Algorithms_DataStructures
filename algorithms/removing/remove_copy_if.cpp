#include "../tools.hpp"

int main(){
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    print("nums: ", nums);

    std::cout << "\nremoving even numbers from nums and copying to a new vector. . . \n" << std::endl;
    std::vector<int> vec; 
    std::remove_copy_if( nums.begin(), nums.end(), std::back_inserter(vec), 
        [](const int & x){
            return x%2==0;
        });

    print("new vector contains only odd numbers: ", vec);
    return 0;
}