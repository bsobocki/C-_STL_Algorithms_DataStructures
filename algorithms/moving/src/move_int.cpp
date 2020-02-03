#include "../../tools.hpp"

int main(){
    std::vector<int> vec = {1, 2, 5, 1, 5, 6, 2, 7, 2};
    std::vector<int> moved_vals( vec.size() );
    
    std::cout << std::endl;
    std::cout << "vec = "; show(vec);
    std::cout << "container that will be used to move values from vector into it = "; show(moved_vals);

    std::cout << std::endl;
    std::cout << "moving value from vec . . ." << std::endl;
    std::move(vec.begin(), vec.end(), moved_vals.begin());
    
    std::cout << std::endl;
    std::cout << "vec = "; show(vec);
    std::cout << "moved values = "; show(moved_vals); 
    
    std::cout << std::endl;
    std::cout << "std::move doesn't remove integers from the vec" << std::endl;

    return 0;
}