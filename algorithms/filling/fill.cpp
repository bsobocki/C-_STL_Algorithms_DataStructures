#include "../tools.hpp"

int main () {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    print("vec: ", vec);

    std::cout << "filling by range . . ." << std::endl;
    std::fill(vec.begin()+2, vec.end()-5, 0);

    print("vec after filling: ", vec);

    std::cout << "filling giving n . . ." << std::endl;
    std::fill_n(vec.begin()+8, 4, 1);

    print("vec after filling: ", vec);
    
    return 0;
}