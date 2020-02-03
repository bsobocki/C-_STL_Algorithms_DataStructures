#include "../../tools.hpp"

int main(){
    std::vector<int> vec = {1, 3, 5, 7, 9};
    std::cout << "vec: "; show(vec);

    std::cout << "\nmoved vector . . .\n" << std::endl;

    std::vector<int> moved = std::move(vec);
    std::cout << "vec: "; show(vec);
    std::cout << "moved: "; show(moved);

    return 0;
}