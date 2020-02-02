#include <vector>
#include <algorithm>
#include "../tools.hpp"


int main() {
    std::vector<int> vec = {1, 400, 2, 500, 7, 1, 29, 8, 2, 1, 340, 4, 0, 1, 1, 111, 345, 624, 725, 838, 751, 90};
    std::cout << "vec = " << to_string(vec) << std::endl;

    std::replace(vec.begin(), vec.end(), 1, 101);

    std::cout << "vec after replace 1 by 101 = " << to_string(vec) << std::endl;

    std::replace_if(vec.begin(), vec.end(), [](const int & x) -> bool { return x < 100; }, 42 );
    std::cout << "vec after replace x<100 by 42 = " << to_string(vec) << std::endl;

    return 0;
}