#include "../tools.hpp"


int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    std::cout << "vec = " << to_string(vec) << std::endl;

    std::reverse(vec.begin(), vec.end());

    std::cout << "reversed vec = " << to_string(vec) << std::endl;

    std::vector<int> vec2 = {100, 200 ,300, 400, 5, 6, 7, 8, 9, 10, 1000, 1100, 1300};
    std::cout << "\nvec2 = " << to_string(vec2) << std::endl;

    std::reverse(vec2.begin()+4, vec2.end()-3);

    std::cout << "reversed vec2 inf range [fifth, tenth]= " << to_string(vec2) << std::endl;

    return 0;
}