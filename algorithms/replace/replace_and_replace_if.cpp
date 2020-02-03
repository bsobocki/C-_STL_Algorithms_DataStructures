#include <vector>
#include <algorithm>
#include "../tools.hpp"


int main() {
    std::vector<int> vec = {1, 2, 5, 7, 8, 11, 13, 15, 16, 17, 19, 21, 22, 9, 10, 8};
    std::cout << "vec = " << to_string(vec) << std::endl;

    std::replace(vec.begin(), vec.end(), 8, 9);

    std::cout << "vec after replace 8 by 9 = " << to_string(vec) << std::endl;

    std::replace(vec.begin(), vec.end(), 9, 42);

    std::cout << "vec after replace 9 by 42 = " << to_string(vec) << std::endl;

    std::replace_if(vec.begin(), vec.end(), [](const int & x) -> bool { return x%2 != 0; }, 0 );
    std::cout << "vec after replace x%2!=0 by 0 = " << to_string(vec) << std::endl;

    return 0;
}