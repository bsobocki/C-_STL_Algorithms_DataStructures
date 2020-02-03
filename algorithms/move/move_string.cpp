#include "../tools.hpp"

int main(){
    std::vector<std::string> vec = {"kad", "fad", "mad", "uouo", "klio"};
    std::vector<std::string> moved;

    std::cout<< " vec = "; show(vec);
    std::cout<< " moved = "; show(moved);

    std::cout << std::endl;
    std::move(vec.begin(), vec.end(), std::back_inserter(moved));

    std::cout << std::endl;
    std::cout<< " vec = "; show(vec);
    std::cout<< " moved = "; show(moved);

    return 0;
}