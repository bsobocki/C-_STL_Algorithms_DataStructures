#include "../tools.hpp"

int main(){
    std::vector<int> first {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> second {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    std::cout << std::endl;
    std::cout << "first: "; show(first);
    std::cout << "second: "; show(second);

    std::cout << std::endl;
    std::cout << "swapping ranges . . ." << std::endl;
    std::swap_ranges(first.begin(), first.begin()+5, second.begin());

    std::cout << std::endl;
    std::cout << "first: "; show(first);
    std::cout << "second: "; show(second);
    
    return 0;
}