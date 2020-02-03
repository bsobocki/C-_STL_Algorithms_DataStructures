#include "../tools.hpp"

int main(){
    std::cout << " ---- arrays ---- " << std::endl;

    float fls[4] = {1.5, 0.7, 3.5, 6.2};
    std::cout << "floats1: "; show(fls, 4);

    std::cout << "swap elements: first and third . . ." << std::endl;
    std::swap(fls[0], fls[2]);

    std::cout << "floats1: "; show(fls, 4);

    float fls2[4] = {0.1, 0.2, 0.3, 0.4};
    std::cout << "\nfloats2: "; show(fls2, 4);

    std::cout << "swap float arrays: . . ." << std::endl;
    std::swap(fls, fls2);

    std::cout << "floats1: "; show(fls, 4);
    std::cout << "floats2: "; show(fls2, 4);
    
    std::cout << std::endl;

    std::cout << " ---- vectors ---- " << std::endl;
    
    std::vector<int> ints = {1,2,3,4,5};
    std::vector<int> no_ints;

    std::cout << "ints: "; show(ints);
    std::cout << "no_ints: "; show(no_ints);

    std::cout << "swap vectors: . . ." << std::endl;
    std::swap(ints, no_ints);

    std::cout << "ints: "; show(ints);
    std::cout << "no_ints: "; show(no_ints);

    return 0;
}