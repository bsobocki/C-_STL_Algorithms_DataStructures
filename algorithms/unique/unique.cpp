#include "../tools.hpp"

int main(){
    std::vector<int> nums = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    print("nums: ", nums);

    std::cout << "\nunique values from nums . . . \n" << std::endl;
    auto new_nums_end_iter = std::unique(nums.begin(), nums.end());
    print("new vector: ", nums);

    std::cout << "\nresize nums based on the iterator returned by std::unique . . . \n" << std::endl;
    nums.resize( std::distance( nums.begin(), new_nums_end_iter ) );
    print("new vector: ", nums);

    std::cout<<std::endl;

    std::cout << "\n\nHmm okay... let's try it with the another vector 'vec'\n\n" << std::endl;

    std::vector<int> vec = {1,1,1, 2,2,2, 3,3,3 ,4,4,4, 5,5,5, 4,4,4, 5,5,5, 6,6, 7};
    print("vec: ", vec);

    std::cout << "\nunique values from vec . . . \n" << std::endl;
    auto new_vec_end_iter = std::unique(vec.begin(), vec.end());
    print("new vector: ", vec);

    std::cout << "\nresize vec based on the iterator returned by std::unique . . . \n" << std::endl;
    vec.resize( std::distance( vec.begin(), new_vec_end_iter ) );
    print("new vector: ", vec);

    return 0;
}