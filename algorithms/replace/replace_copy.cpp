#include "../tools.hpp"

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    std::cout << "vec = " << to_string(vec) << std::endl;

    std::vector<int> new_vec (vec.size());
    std::cout << "new_vec = " << to_string(new_vec) << std::endl;

    std::cout << "\ncopying and replacing values (replace 10 by 9) . . .\n" << std::endl;
    std::replace_copy(vec.begin(), vec.end(), new_vec.begin(), 10, 9);

    std::cout << "new_vec = " << to_string(new_vec) << std::endl;


    std::cout << "\ncopying and replacing even numbers (replace odd numbers by 0) . . .\n" << std::endl;
    std::replace_copy_if(
        vec.begin(), 
        vec.end(), 
        std::back_inserter(new_vec), 
        [](const int & x) -> bool { 
            return x%2 != 0; 
        }, 
        0 
    );

    std::cout << "new_vec now: = " << to_string(new_vec) << std::endl;

    return 0;
}